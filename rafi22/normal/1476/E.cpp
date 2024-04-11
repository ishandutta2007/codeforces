#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int is[1000007];
string p[100007],s[100007];
int mt[100007];
int pot[4]={1,31,961,29791};
vector<int>G[100007];
int ile[100007];
bool odw[100007];
deque<int>Q;

void gg()
{
    cout<<"NO";
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            int h=0;
            for(int j=0;j<k;j++)
            {
                if(p[i][j]=='_') h+=26*pot[j];
                else h+=(p[i][j]-'a')*pot[j];
            }
            is[h]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>s[i]>>mt[i];
            bool ok=0;
            for(int x=0;x<(1<<k);x++)
            {
                int h=0;
                for(int j=0;j<k;j++)
                {
                    if((x&(1<<j))) h+=26*pot[j];
                    else h+=(s[i][j]-'a')*pot[j];
                }
                if(is[h])
                {
                    if(is[h]==mt[i]) ok=1;
                    else
                    {
                        G[mt[i]].pb(is[h]);
                        ile[is[h]]++;
                    }
                }
            }
            if(!ok) gg();
        }
        for(int i=1;i<=n;i++) if(ile[i]==0) Q.pb(i);
        vector<int>ans;
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            odw[v]=1;
            ans.pb(v);
            for(auto u:G[v])
            {
                ile[u]--;
                if(ile[u]==0) Q.pb(u);
            }
        }
        for(int i=1;i<=n;i++) if(!odw[i]) gg();
        cout<<"YES"<<endl;
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}
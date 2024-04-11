#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int N=207;

int p[N];
int pos[N];
bool odw[N];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            pos[p[i]]=i;
        }
        vector<int>q;
        memset(odw,0,sizeof odw);
        for(int l=1;l<=n;l++)
        {
            int i=pos[l];
            if(odw[i]) continue;
            vector<int>V;
            int x=i;
            while(!odw[x])
            {
                V.pb(p[x]);
                odw[x]=1;
                x=p[x];
            }
            reverse(all(V));
            vector<int>nq;
            if(sz(q)==0) nq=V;
            for(int j=0;j<sz(q);j++)
            {
                nq.pb(q[j]);
                if(q[j]==p[i]-1)
                {
                    for(auto x:V) nq.pb(x);
                }
            }
            q=nq;
        }
        for(auto x:q) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>

//#define int long long
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

struct S
{
    int l,r,i;
};

unordered_map<string,S>M;
bool DP[1007];
S zkad[1007];

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
        M.clear();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                string x;
                if(j>=1)
                {
                    x="";
                    x+=s[j-1];
                    x+=s[j];
                    M[x]={j,j+1,i};
                }
                if(j>=2)
                {
                    x="";
                    x+=s[j-2];
                    x+=s[j-1];
                    x+=s[j];
                    M[x]={j-1,j+1,i};
                }
            }
        }
        string s;
        cin>>s;
        s='#'+s;
        DP[0]=1;
        for(int i=1;i<=m;i++) DP[i]=0;
        for(int i=1;i<=m;i++)
        {
            string x;
            if(i>1)
            {
                x="";
                x+=s[i-1];
                x+=s[i];
                if(DP[i-2]&&M[x].i>0)
                {
                    DP[i]=1;
                    zkad[i]=M[x];
                }
            }
            if(i>2)
            {
                x="";
                x+=s[i-2];
                x+=s[i-1];
                x+=s[i];
                if(DP[i-3]&&M[x].i>0)
                {
                    DP[i]=1;
                    zkad[i]=M[x];
                }
            }
        }
        if(!DP[m])
        {
            cout<<-1<<endl;
            continue;
        }
        vector<S>ans;
        while(m)
        {
            ans.pb(zkad[m]);
            m-=(zkad[m].r-zkad[m].l+1);
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.l<<" "<<x.r<<" "<<x.i<<endl;
    }

    return 0;
}
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

const bool multi=0;

ld DP[(1<<20)+7];
ld p[27];
ld rp[27];
ld ans[27];
int id[27];

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
        int n,k;
        cin>>n>>k;
        int it=-1;
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++)
        {
            if(p[i]!=0)
            {
                rp[++it]=p[i];
                id[i]=it;
            }
            else id[i]=-1;
        }
        it++;
        k=min(k,it);
        DP[0]=1;
        for(int i=0;i<1<<it;i++)
        {
            ld sum=0;
            int c=n;
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&i)) continue;
                sum+=rp[j];
                c--;
            }
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&i))
                {
                    if(c==k) ans[j]+=DP[i];
                    continue;
                }
                DP[i|(1<<j)]+=DP[i]*(rp[j]/sum);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(id[i]==-1) cout<<0<<" ";
            else cout<<fixed<<setprecision(8)<<ans[id[i]]<<" ";
        }
    }

    return 0;
}
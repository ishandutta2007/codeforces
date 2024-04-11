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

const bool multi=1;

int DP[80][80];
bool skad[80][80];
bool was[80];
pair<pair<int,int>,int>a[80];

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
        memset(skad,0,sizeof skad);
        memset(was,0,sizeof was);
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].st.nd>>a[i].st.st;
            a[i].nd=i;
        }
        sort(a+1,a+n+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                DP[i][j]=-inf;
            }
        }
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            DP[i][0]=DP[i-1][0]+(k-1)*a[i].st.st;
            for(int j=1;j<=min(i,k);j++)
            {
                if(DP[i-1][j]+(k-1)*a[i].st.st>=DP[i-1][j-1]+a[i].st.nd+(j-1)*a[i].st.st) DP[i][j]=DP[i-1][j]+(k-1)*a[i].st.st;
                else
                {
                    skad[i][j]=1;
                    DP[i][j]=DP[i-1][j-1]+a[i].st.nd+(j-1)*a[i].st.st;
                }
            }
        }
        cout<<2*n-k<<endl;
        vector<int>ans;
        int N=n;
        while(n>0&&k>0)
        {
            if(skad[n][k])
            {
                ans.pb(a[n].nd);
                was[a[n].nd]=1;
                n--,k--;
            }
            else n--;
        }
        for(int i=sz(ans)-1;i>0;i--) cout<<ans[i]<<" ";
        for(int i=1;i<=N;i++) if(!was[i]) cout<<i<<" "<<-i<<" ";
        cout<<ans[0]<<endl;
    }

    return 0;
}
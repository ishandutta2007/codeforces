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

const int N=2007;

int DP[N];
int l[N],r[N],a[N];
int c[N][N];
int n,k;

int ile(int x,int i)
{
    int b=min(x,a[i]);
    return (a[i]-b)/k+min(1LL,(a[i]-b)%k);
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
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i]>>a[i];
        for(int i=1;i<=n;i++)
        {
            int cnt=k,act=k;
            bool ok=1;
            if(l[i]==r[i-1]) ok=0;
            bool f=0;
            for(int j=i;j<=n;j++)
            {
                int x=ile(act,j);
                if(l[j]!=r[j-1]) f=0;
                if(x>r[j]-l[j])
                {
                    if(f)
                    {
                        cnt+=k;
                        act=k;
                        x=ile(k,j);
                        if(x>r[j]-l[j]) ok=0;
                    }
                    else ok=0;
                }
                if(x==0) act-=a[j];
                else act=x*k-(a[j]-act);
                f|=(x!=r[j]-l[j]);
                cnt+=x*k;
                if(!ok||r[j]==l[j+1]) c[i][j]=inf;
                else
                {
                    if(j==n) c[i][j]=cnt-act;
                    else c[i][j]=cnt;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            DP[i]=inf;
            for(int j=0;j<i;j++) DP[i]=min(DP[i],DP[j]+c[j+1][i]);
        }
        if(DP[n]==inf) cout<<-1;
        else cout<<DP[n];
    }

    return 0;
}
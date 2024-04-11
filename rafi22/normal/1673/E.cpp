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

const int N=(1<<20)+7;

int a[N];
bool ans[N];

int ile[N];
int fac[N];

bool is(int n,int k)
{
    if(min(n,k)<0) return 0;
    if(n<k) return 0;
    if(fac[n]<=fac[k]+fac[n-k]) return 1;
    return 0;
}
bool ok[27][3];

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
        for(int i=1;i<=n;i++) if(i%2==0) ile[i]=ile[i/2]+1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]+ile[i];
        for(int i=0;i<=min(n-1,20LL);i++)
        {
            for(int l=0;l<3;l++)
            {
                for(int j=k-l;j<=n-1-l-i;j++) ok[i][l]^=is(n-1-l-i,j);
            }
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int x=1;
            for(int j=i;j<=n;j++)
            {
                if(j!=i&&a[j]>20) break;
                if(j!=i) x*=(1<<a[j]);
                else x*=a[j];
                if(x>=(1<<20)) break;
                if(ok[j-i][(i!=1)+(j!=n)]) ans[x]^=1;
            }
        }
        int c=0;
        for(int i=(1<<20);i>0;i--)
        {
            if(ans[i])
            {
                c=i;
                break;
            }
        }
        for(int i=c;i>=0;i--) cout<<ans[i];
    }

    return 0;
}
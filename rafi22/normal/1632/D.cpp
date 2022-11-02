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

const bool multi=0;

const int N=200007;

int a[18][N];
int lg[N];
int DP[N];

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
        for(int i=1;i<=n;i++) cin>>a[0][i];
        for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
        for(int j=1;j<18;j++) for(int i=1;i<=n-(1<<j)+1;i++) a[j][i]=__gcd(a[j-1][i],a[j-1][i+(1<<(j-1))]);
        for(int i=1;i<=n;i++)
        {
            int l=1,r=i,sr,k=-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                int d=lg[i-sr+1];
                int g=__gcd(a[d][sr],a[d][sr+(i-sr+1)-(1<<d)]);
                if(g<i-sr+1) l=sr+1;
                else if(g==i-sr+1)
                {
                    k=sr;
                    break;
                }
                else r=sr-1;
            }
            if(k==-1) DP[i]=DP[i-1];
            else DP[i]=DP[k-1]+1;
            cout<<DP[i]<<" ";
        }
    }


    return 0;
}
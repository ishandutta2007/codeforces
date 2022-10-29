#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head


const int N=5005;
int n,x,a[N];
int ans[N];
int sum[N],suf[N];

int main() {
    int _;
    for (cin>>_;_;_--) {
        scanf("%d%d",&n,&x);
        rep(i,1,n+2) ans[i]=-inf;
        rep(i,1,n+1) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
        rep(i,1,n+1) {
            for (int l=1;l+i-1<=n;l++) {
                int r=l+i-1;   
                ans[i]=max(ans[i],sum[r]-sum[l-1]);  
            }
        } 
        suf[n+1]=-inf;
        per(i,n+1,1) suf[i]=max(ans[i],suf[i+1]);
        int ret=0;
        // max(ans[i]+k*t) t<=i
        // i>t ans[i]+k*t
        // i<=t ans[i]+i*t
        for (int i=0;i<=n;i++) {
            ret=max(ret,ans[i]+i*x);
            printf("%d ",max(suf[i+1]+x*i,ret));
            
        }
        puts("");
        
    }
    
    return 0;    
}
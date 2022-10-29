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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head


const int N=1e6+5;
int cnt[N],a[N],sum[N];
int n,c;

int main() {
    int _;
    for (cin>>_;_;_--) {
        scanf("%d%d",&n,&c);
        rep(i,1,n+1) scanf("%d",&a[i]),cnt[a[i]]++;
        bool flag=1;
        rep(i,1,c+1) {
            sum[i]=sum[i-1]+cnt[i];
            if (cnt[i]>1&&!cnt[1]) flag=0;
        }
        for (int i=2;i<=c;i++) if (cnt[i]) {
            for (int j=i;j<=c;j+=i) {
                int l=j,r=min(c,j+i-1);
                // [l,r] / i == j/i
                if (sum[r]-sum[l-1]>0) {
                    if (!cnt[l/i]) flag=0;   
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (flag) puts("Yes");
        else puts("No");
        rep(i,0,c+1) cnt[i]=sum[i]=0;
    }
    
    return 0;    
}
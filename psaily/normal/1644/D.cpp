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

const int N=2e5+5;
const int mod=998244353;
int n,m,k,q;
PII Q[N];
ll ans;
int visx[N],visy[N];

int main() {
    int _,id=0;
    set<int> X,Y;
    for (cin>>_;_;_--) {
        id++;
        ans=1;
       scanf("%d%d%d%d",&n,&m,&k,&q);
       rep(i,1,q+1) {
            scanf("%d%d",&Q[i].fi,&Q[i].se);
       }
       int xr=n,yr=m;
       per(i,q+1,1) {
            int x=Q[i].fi,y=Q[i].se;
            bool flag=0;
            if (visx[x]!=id) {
                if (yr>0) flag=1;
            }    
            if (visy[y]!=id) {
                if (xr>0) flag=1;   
            }
            if (flag) {
                ans=ans*k%mod;
                if (visx[x]!=id) xr--;
                if (visy[y]!=id) yr--;
                visx[x]=visy[y]=id;
            }
        }
       printf("%lld\n",ans);
    }
    
    return 0;    
}
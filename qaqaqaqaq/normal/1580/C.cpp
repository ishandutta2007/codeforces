// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=200007;
const int mod=998244353;
const int B=500;
int n,m;
int x[maxn],y[maxn];
int st[maxn],ans[maxn],prv[maxn];
int cnt[507][507];
vi evnt[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rep1(i,n) cin>>x[i]>>y[i];
    rep1(i,m){
        int op,w;
        cin>>op>>w;
        if (op==1){
            if (x[w]+y[w]<=B){
                for (int j=0;j<y[w];++j) cnt[x[w]+y[w]][(i+x[w]+j)%(x[w]+y[w])]++;
                prv[w]=i;
            }
            else{
                evnt[w].pb(i);
            }
            for (int j=1;j<=B;++j) ans[i]+=cnt[j][i%j];

        }
        else{
            if (x[w]+y[w]<=B){
                for (int j=0;j<y[w];++j) cnt[x[w]+y[w]][(prv[w]+x[w]+j)%(x[w]+y[w])]--;
            }
            else{
                evnt[w].pb(i);
            }
            for (int j=1;j<=B;++j) ans[i]+=cnt[j][i%j];
        }
    }
    rep1(i,n){
        if (x[i]+y[i]<=B) continue;
        if (sz(evnt[i])&1) evnt[i].pb(m+1);
        rep(j,sz(evnt[i])/2){
            int beg=evnt[i][j*2], ed=evnt[i][j*2+1];
            for (int k=beg+x[i];k<=ed;k+=x[i]+y[i]){
                st[k]++, st[min(k+y[i],ed)]--;
            }
        }
    }
    for (int i=1;i<=m;++i) st[i]+=st[i-1];
    for (int i=1;i<=m;++i) {ans[i]+=st[i]; cout<<ans[i]<<"\n";}

}
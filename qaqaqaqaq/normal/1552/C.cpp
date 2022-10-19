#include<bits/stdc++.h>
#define int long long

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

// using namespace std;
const int maxn=207;
int n,m;
int a[maxn],b[maxn];
bool vis[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        rep(i,m) cin>>a[i]>>b[i];
        rep(i,m) vis[a[i]]=vis[b[i]]=1;
        vi rem;
        rem.clear();
        rep1(i,2*n){
            if (!vis[i]) rem.pb(i);
        } 
        rep(i,n-m){
            a[i+m]=rem[i], b[i+m]=rem[i+n-m];
        }
        rep(i,n) {
            if (a[i]>b[i]) swap(a[i],b[i]); 
        }
        int ans=0;
        rep(i,n) rep(j,i){
            int u=(a[j]-a[i]+2*n)%(2*n), v=(b[j]-a[i]+2*n)%(2*n), w=b[i]-a[i];
            if ((u-w)*(v-w)<0) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
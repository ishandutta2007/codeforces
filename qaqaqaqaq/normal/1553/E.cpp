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

const int maxn=300007;


int n,k;
int p[maxn];
bool vis[maxn];
mt19937 rng(time(NULL));
signed main(){
    int _;
    cin>>_;
    while (_--){
        cin>>n>>k;
        rep(i,n) cin>>p[i], p[i]--;
        vi ans;
        ans.clear(); 
        rep(_,n){
            bool ok=0;
            rep(__,80){
                int rd=rng()%n;
                if (p[rd]==(rd-_+n)%n) ok=1;
            }
            if (!ok) continue;
            rep(i,n) vis[i]=0;
            int cnt=0;
            rep(i,n){
                if (vis[i]) continue;
                int bg=i,nw=i;
                vis[bg]=1;
                while (1){
                    nw=p[(nw+_)%n];
                    vis[nw]=1;
                    if (nw==bg) break;
                }
                cnt++;
            }
            if (n-cnt<=k) ans.pb(_);
        }
        cout<<sz(ans)<<" ";
        for (auto c:ans) cout<<c<<" ";
        cout<<"\n";
    }
    return 0;
}
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
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--){
        // memset(vis,0,sizeof(vis));
        cin>>n;
        rep(i,n) cin>>a[i];
        bool ok=0;
        rep(i,1<<n){
            if (!i) continue;
            vi v;
            v.clear();
            rep(j,n){
                if (i>>j&1) v.pb(abs(a[j]));
            }
            int m=sz(v);
            rep(j,1<<m){
                int sum=0;
                rep(k,m){
                    if (j>>k&1) sum+=v[k];
                    else sum-=v[k]; 
                }
                if (!sum) ok=1;
            }
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
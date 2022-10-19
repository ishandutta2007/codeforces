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
const int maxn=10007;
int n,m;
int c[maxn],d[maxn];
int ansl[maxn],ansr[maxn];
bool vis[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rep1(i,n*m){
        // int u;
        cin>>c[i];
    }
    // auto block=[&](int u){
    //     return (u-1)/(n*m/(m-1));
    // };
    // auto ck_uni=[&](info l){
    //     return block(l.l)==block(l.r);
    // };
    auto block=[&](int u){
        return (u-1)/(m-1);
    };
    rep(_,(n+m-2)/(m-1)) {
        set<int> s;
        s.clear();
        rep1(i,n*m){
            if (block(c[i])!=_) continue;
            if (vis[c[i]]) continue;
            if (s.find(c[i])!=s.end()){
                ansl[c[i]]=d[c[i]], ansr[c[i]]=i;
                vis[c[i]]=1; s.clear();
            }
            else{
                d[c[i]]=i; s.insert(c[i]);
            }
        }
    }
    rep1(i,n) {
        assert(vis[i]);
        cout<<ansl[i]<<" "<<ansr[i]<<"\n";
    }
    return 0;
}
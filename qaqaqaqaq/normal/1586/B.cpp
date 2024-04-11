// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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


const int maxn=1000007;
const int mod=998244353;

string s[maxn];
int n,m;
bool vis[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>m;
        rep1(i,n) vis[i]=0;
        rep(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            vis[v]=1;
        }
        for (int i=1;i<=n;++i){
            if (vis[i]) continue;
            rep1(j,n){
                if (i==j) continue;
                cout<<i<<" "<<j<<"\n";
            }
            break;
        }
    }
    return 0;
}
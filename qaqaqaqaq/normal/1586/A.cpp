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
int a[maxn];

bool is_comp(int u){
    if (u<=3) return 0;
    for (int i=2;i*i<=u;++i){
        if (u%i==0) return 1;
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        int sum=0;
        rep(i,n) cin>>a[i];
        rep(i,n) sum+=a[i];
        if (is_comp(sum)){
            cout<<n<<"\n";
            rep(i,n) cout<<i+1<<" ";
            cout<<"\n";
            continue;
        }
        rep(i,n){
            if (is_comp(sum-a[i])){
                cout<<n-1<<"\n";
                rep(j,n){
                    if (j==i) continue;
                    cout<<j+1<<" ";
                }
                cout<<"\n";
                break;
            }
        }
    }
    return 0;
}
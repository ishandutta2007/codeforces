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
int n,k;
int b[maxn][20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>k;
    vi res;
    for (int i=0;i<n;++i){
        int w=i;
        rep(j,20){
            b[i][j]=w%k;
            w/=k;
        }
    }
    int mx=0;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (i==j) continue;
            for (int k=19;k>-1;--k){
                if (b[i][k]!=b[j][k]) {res.pb(k); break;} 
            }
        }
    }
    for (auto c:res) mx=max(mx,c);
    cout<<mx+1<<"\n";
    for (auto c:res) cout<<c+1<<" ";
    return 0;
}
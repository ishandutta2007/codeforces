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
int n,m,q;
int cnt[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>m;
    rep(i,n) cin>>s[i];
    for (int i=1;i<m;++i){
        bool ok=1;
        rep1(j,n-1){
            if (s[j-1][i]=='X'&&s[j][i-1]=='X') ok=0;
        }
        if (!ok) cnt[i]++;
    }
    for (int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
    cin>>q;
    while (q--){
        int l,r;
        cin>>l>>r;
        l--, r--;
        if (cnt[l]==cnt[r]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
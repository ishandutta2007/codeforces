#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}

int n,a[N],b[N],len[N][2];

bool check1(int i,int j){
    if (a[i] > b[j]) return 0;
    return (len[j][0] >= j-i);
}
int  bs1(int i){
    int l = i,r = n,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check1(i,m)) l = m;
        else r = m;
    }
    return l;
}
bool check2(int i,int j){
    if (a[i] > b[j]) return 0;
    return (len[j][1] >= i-j);
}
int  bs2(int i){
    int l = -1,r = i,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check2(i,m)) r = m;
        else l = m;
    }
    return r;
}

void solve(){
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    rep(i,1,n){
       if (a[i] > b[i-1]) len[i][0] = 0;
       else len[i][0] = 1+len[i-1][0];
    }
    len[n-1][1] = 0;
    repr(i,n-2,0){
       if (a[i] > b[i+1]) len[i][1] = 0;
       else len[i][1] = 1+len[i+1][1];
    }
    rep(i,0,n) cout << b[bs2(i)]-a[i] << ' ';
    cout << endl;
    rep(i,0,n) cout << b[bs1(i)]-a[i] << ' ';
    cout << endl;
    return;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
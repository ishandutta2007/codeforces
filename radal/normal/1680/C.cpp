#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
        k >>= 1;
    } 
    return z;
}
int pre[N][2];
inline void solve(){
    string s;
    cin >> s;
    int n = s.size(),ans;
    rep(i,0,n){
        if (s[i] == '0'){
            pre[i][0] = 1;
            pre[i][1] = 0;
        }
        else{
            pre[i][0] = 0;
            pre[i][1] = 1;
        }
        if (i) rep(j,0,2) pre[i][j] += pre[i-1][j];
    }
    ans = min(pre[n-1][0],pre[n-1][1]);
    if (pre[n-1][1] < 2){
        cout << 0 << endl;
        return;
    }
    rep(i,0,n){
        if (i+pre[n-1][1]-1 >= n) break;
        int cnt0 = pre[i+pre[n-1][1]-1][0],cnt1 = pre[n-1][1]-pre[i+pre[n-1][1]-1][1];
        if (i){
            cnt0 -= pre[i-1][0];
            cnt1 += pre[i-1][1];
        }
        ans = min(ans,max(cnt1,cnt0));
    }
    rep(i,0,n){
        if (pre[n-1][1]+i-2 >= n) break;
        int cnt0 = pre[i+pre[n-1][1]-2][0],cnt1 = pre[n-1][1]-pre[i+pre[n-1][1]-2][1];
        if (i){
            cnt0 -= pre[i-1][0];
            cnt1 += pre[i-1][1];
        }
        ans = min(ans,max(cnt1,cnt0));
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}
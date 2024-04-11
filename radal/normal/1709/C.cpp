#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
inline void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt[3] = {0,0,0};
    rep(i,0,n){
        if (s[i] == '?') cnt[0]++;
        else if (s[i] == '(') cnt[1]++;
        else cnt[2]++;
    }
    if (cnt[0] < 2 || max(cnt[1],cnt[2]) == n/2){
        cout << "YES" << endl;
        return;
    }
    int x = n/2;
    bool f = 0;
    rep(i,0,n){
        if (s[i] != '?') continue;
        if (cnt[1] < x-1 || (cnt[1] < x && f)){
            s[i] = '(';
            cnt[1]++;
            continue;
        }
        f = 1;
        s[i] = ')';
        cnt[2]++;
        continue;
    }
    int pr = 0;
    rep(i,0,n){
        if (s[i] == '(') pr++;
        else pr--;
        if (pr < 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
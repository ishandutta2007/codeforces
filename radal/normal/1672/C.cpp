#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
constexpr int N = 4e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int a[N];
inline void solve(){
    int n;
    cin >> n;
    vector<int> ve;
    int cnt = 0,t = 0,cur = 0,beg = -1,en = -1;
    rep(i,0,n){
        cin >> a[i];
        if (i && a[i] == a[i-1]){
            en = i;
            if (beg == -1) beg = i;
            cnt++;
            cur++;
        }
        if (i && a[i] != a[i-1]){
            if (cur) t++;
            cur = 0;
        }
    }
    if (cur) t++;
    if (cnt < 2){
        cout << 0 << endl;
        return;
    }
    if (t == 1 && cnt == 2){
        cout << 1 << endl;
        return;
    }
    cout << en-beg-1 << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}
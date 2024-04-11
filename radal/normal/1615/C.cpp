#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,ll b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int cnt = 0,cnt2 = 0;
        rep(i,0,n){
            if (s[i] == '1') cnt++;
            if (t[i] == '1') cnt2++;
        }
        if (cnt+cnt2 != n+1 && cnt != cnt2){
            cout << -1 << endl;
            continue;
        }
        if (s == t){
            cout << 0 << endl;
            continue;
        }
        int diff = 0;
        rep(i,0,n)
            if (s[i] != t[i])
                diff++;
        if (cnt != cnt2){
            cout << n-diff << endl;
            continue;
        }
        if ((n&1) == 0 || cnt+cnt2 != n+1){
            cout << diff << endl;
            continue;
        }
        cout << min(n-diff,diff) << endl;

    }
}
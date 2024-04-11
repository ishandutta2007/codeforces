#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        bool f = 1;
        rep(i,0,n){
            if (s[i] != c){
                f = 0;
                break;
            }
        }
        if (f){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        rep(i,2,n+1){
            f = 1;
            for (int j = 1; j*i <= n; j++){
                if (s[j*i-1] != c){
                    f = 0;
                    break;
                }
            }
            if (f){
                ans = i;
                break;
            }
        }
        if (f){
            cout << 1 << endl << ans << endl;
            continue;
        }
        cout <<2 << endl << n << ' ' << n-1 << endl;
    }
}
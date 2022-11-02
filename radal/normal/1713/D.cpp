#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 5e5+10,mod = 998244353,inf = 1e9+10,sq = 700;
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
vector<int> ve[40];
void solve(){
    int n;
    cin >> n;
    rep(i,0,40) ve[i].clear();
    int y = (1 << n);
    rep(i,1,y+1) ve[0].pb(i);
    int i = 0;
    while (1){
        i++;
        if (ve[i-1].size() == 1){
            cout << "! " << ve[i-1][0] << endl;
            return;
        }
        if (ve[i-1].size() == 2){
            cout << "? " << ve[i-1][0] << ' ' << ve[i-1][1] << endl;
            int x;
            cin >> x;
            if (x == 1){
                ve[i].pb(ve[i-1][0]);
            }
            else{
                ve[i].pb(ve[i-1][1]);
            }
            continue;
        }
        int sz = ve[i-1].size();
        for (int j = 0; j < sz; j += 4){
            cout << "? " << ve[i-1][j] << ' ' << ve[i-1][j+2] << endl;
            int x;
            cin >> x;
            if (!x){
                cout << "? " << ve[i-1][j+1] << ' ' << ve[i-1][j+3] << endl;
                cin >> x;
                if (x == 1){
                    ve[i].pb(ve[i-1][j+1]);
                }
                else
                    ve[i].pb(ve[i-1][j+3]);
                continue;
            }
            if (x == 1){ 
                cout << "? " << ve[i-1][j] << ' ' << ve[i-1][j+3] << endl;
                cin >> x;
                if (x == 1){
                    ve[i].pb(ve[i-1][j]);
                }
                else
                    ve[i].pb(ve[i-1][j+3]);
                continue;
            }
            if (x == 2){ 
                cout << "? " << ve[i-1][j+1] << ' ' << ve[i-1][j+2] << endl;
                cin >> x;
                if (x == 1){
                    ve[i].pb(ve[i-1][j+1]);
                }
                else
                    ve[i].pb(ve[i-1][j+2]);
                continue;
            }
        }
    }
}
int main(){
 //   ios :: sync_with_stdio(0); cin.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }

}
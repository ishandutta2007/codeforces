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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e18+10,sq = 32000;
inline int mkay(int a,int b){
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
bool mark[N];
int fx[N];
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1; 
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1){
            mark[i] = 0;
            fx[i] = -1;
        }
        rep(i,1,n+1){
            if (fx[i] == -1){
                cout << "? " << i << endl;
                int cur;
                cin >> cur;
                while (!mark[cur]){
                    cout << "? " << i << endl;
                    int x;
                    cin >> x;
                    fx[cur] = x;
                    mark[cur] = 1;
                    cur = x;
                }
            }
        }
        cout << "! ";
        rep(i,1,n+1) cout << fx[i] << ' ';
        cout << endl;
    }
}
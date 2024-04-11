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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
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
int b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,m,k;
        cin >> n >> m >> k;
        int v = n/m,r = n%m;
        rep(i,1,n+1) b[i] = 0;
        rep(i,1,k+1){
            int mx = 0;
            rep(j,1,n+1){
                mx = max(mx,b[j]);
            }
            set<int> st1,st2;
            rep(j,1,n+1){
                if (b[j] == mx) st1.insert(j);
                else st2.insert(j);
            }
            rep(j,1,r+1){
                vector<int> ve;
                int cnt = v+1;
                while (!st2.empty() && cnt){
                    int u = *(st2.begin());
                    b[u]++;
                    ve.pb(u);
                    cnt--;
                    st2.erase(u);
                }
                while (cnt){
                    int u = *(st1.begin());
                    b[u]++;
                    ve.pb(u);
                    cnt--;
                    st1.erase(u);
                }
                cout << ve.size() << ' ';
                for (int u : ve) cout << u << ' ';
                cout << "\n";
            }
            rep(j,r,m){
                int cnt = v;
                vector<int> ve;
                while (!st2.empty() && cnt){
                    int u = *(st2.begin());
                    ve.pb(u);
                    cnt--;
                    st2.erase(u);
                }
                while (cnt){
                    int u = *(st1.begin());
                    ve.pb(u);
                    cnt--;
                    st1.erase(u);
                }
                cout << ve.size() << ' ';
                for(int u : ve) cout << u << ' ';
                cout << "\n";
            }
            cout << "\n";
        }
    }
}
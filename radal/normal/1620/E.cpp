#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//#pragma GCC optimize("unroll-loops")
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

constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 18)+10;
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
vector<int> ind[N];
int s[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    int n = 0;
    rep(i,0,q){
        int t;
        int a,b;
        cin >> t >> a;
        if (t == 1){
            ind[a].pb(n);
            n++;
            continue;
        }
        cin >> b;
        if (a == b) continue;
        if (ind[a].size() > ind[b].size()) ind[a].swap(ind[b]);
        while (!ind[a].empty()){
            ind[b].pb(ind[a].back());
            ind[a].pop_back();
        }
    }
    rep(i,0,N){
        for (int j : ind[i])
            s[j] = i;
    }
    rep(i,0,n) cout << s[i] << ' ';
}
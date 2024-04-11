#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr long long int N = 1e6+20,mod = 1e9+7 ,inf = 1e18+10;
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
int ans[N],mx[N][2],par[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(mx,-1,sizeof mx);
    int n;
    cin >> n;
    rep(i,2,n+2){
        int v;
        cin >> v;
        par[i] = v;
        ans[i] = 1;
        if (ans[v] > 1){
            cout << mx[1][0] << ' ';
            continue;
        }
        int cur = i;
        while (cur > 1){
            int p = par[cur];
            if (mx[p][0] < ans[cur]){
                mx[p][0] = ans[cur];
            }
            else if (mx[p][1] < ans[cur]){
                mx[p][1] = ans[cur];
            }
            if (ans[p] >= max(mx[p][0],mx[p][1]+1)) break;
            ans[p] = max(mx[p][0],mx[p][1]+1);
            cur = p;
        }
        cout << mx[1][0] << ' ';
    }
}
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
const long long int N = 1e2+20,mod = 1e9+7,inf = 4e18+10,sq = 400;
inline int mkay(int a,ll b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k,int m){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%m;
        n = (1ll*n*n)%m;
        k >>= 1;
    }
    return c;
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int l1,l2,l3;
        cin >> l1 >> l2 >> l3;
        if (l1 < l2) swap(l1,l2);
        if (l1 < l3) swap(l1,l3);
        if (l2 < l3) swap(l2,l3);
        if (l1 == l2+l3 || (l1 == l2 && l3%2 == 0) || (l2 == l3 && l1%2 == 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
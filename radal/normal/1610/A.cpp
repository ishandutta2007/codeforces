#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
typedef pair<long double,long double> pld;
const long long int N = 5e4+10,mod = 998244353,inf = 1e9,sq = 700,maxm = 2e5+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline ll poww(int n,int k){
    ll c = 1;
    while (k){
        if (k&1) c = (c*n)%mod;
        n = (n*n)%mod;
        k >>= 1;
    }
    return c;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        if (n > m) swap(n,m);
        if (n == m && n == 1){
            cout << 0 << endl;
            continue;
        }
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}
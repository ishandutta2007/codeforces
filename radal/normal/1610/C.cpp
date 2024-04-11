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
const long long int N = 2e5+10,mod = 998244353,inf = 1e9,sq = 700,maxm = 2e5+10;
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
int a[N],b[N];
int n;
bool check(int k){
    int cnt = 0;
    rep(i,0,n)
        if (b[i] >= cnt && k-(cnt+1) <= a[i])
            cnt++;
    return (cnt >= k);
}
inline int bs(){
    int l = 0,r = n+1,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        rep(i,0,n) cin >> a[i] >> b[i];
        cout << bs() << endl;
    }
    return 0;
}
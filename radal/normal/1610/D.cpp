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
const long long int N = 2e5+10,mod = 1e9+7,inf = 1e9,sq = 700,maxm = 2e5+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (c*n)%mod;
        n = (n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N],pw[N];
int n;
bool cmp(int x,int y){
    return (x&(-x)) < (y&(-y));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    rep(i,0,n)
        cin >> a[i];
    pw[0] = 1;
    rep(i,1,n+1)
        pw[i] = pw[i-1]*2%mod;
    sort(a,a+n,cmp);
    if (a[0]&1)
        ans = pw[n-1];
    rep(i,0,n){
        int j = i;
        while (i < n && (a[i]&(-a[i])) == (a[j]&(-a[j])))
            i++;
        int x = pw[i-j-1]-1;
        ans = mkay(ans,1ll*x*pw[n-i]%mod);
        i--;
    }
    cout << ans;
    return 0;
}
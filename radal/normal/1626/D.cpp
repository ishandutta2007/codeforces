#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 7e5+20,mod = 1e9+7,inf = 1e18,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int a[N],b[N];
inline int f(int x){
    int z = 1;
    while (z < x) z <<= 1;
    return z-x;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        b[0] = -1;
        rep(i,1,n){
            if (a[i] != a[i-1]) b[i] = i;
            else b[i] = b[b[i-1]];
        }
        int ans = 1000000000;
        rep(i,0,20){
            int x = (1 << i);
            if (x >= n){
                ans = min(ans,x-n+2);
                break;
            }
            int p1 = b[x];
            if (p1 == -1) continue;
            int cnt = x-p1;
            rep(j,0,20){
                int y = (1 << j);
                if (p1+y >= n){
                    ans = min(ans,cnt+p1+y-n+1);
                    break;
                }
                int p2 = b[p1+y];
                ans = min(ans,cnt+y-p2+p1+f(n-p2));
            }
        }
        cout << ans << endl;
    }
}
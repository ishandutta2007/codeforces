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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e18,sq = 400;
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
int cnt[N];
int main(){
    int T = 1;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        if (n < m) swap(n,m);
        int x = n/2,y = m/2;
        rep(i,0,n){
            rep(j,0,m){
                int d = abs(i-x)+abs(j-y);
                d = min({d,abs(i-(n-1)/2)+abs(j-y),abs(i-x)+abs(j-(m-1)/2),abs(i-(n-1)/2)+abs(j-(m-1)/2)});
                cnt[d]++;
            }
        }
        int p= 0;
        rep(i,0,m*n){
            if (!cnt[p]) p++;
            cout << p+n/2+m/2 << ' ';
            cnt[p]--;
        }
        cout << endl;
    }
}
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
const long long int N = 1e6+20,mod = 1e9+7,inf = 1e18,sq = 400;
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
bool a[N];
int b[N];
int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    int g;
    rep(i,0,n){
        cin >> b[i];
        if (!i) g = b[i];
        else g = gcd(b[i],g);
    }
    rep(i,0,n){
        b[i] /= g;
        a[b[i]] = 1;
    }
    int ans = 0;
    rep(i,1,N){
        int g = -1,cnt = 0;
        if (!a[i]){
            for (int j = 2; j*i < N; j++){
                if (a[j*i]){
                    cnt++;
                    if (g == -1) g = j*i;
                    else g = gcd(g,j*i);
                    if (g == i) break;
                }
            }
            if (g == i) ans++;
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e3+20,mod = 998244353 ,inf = 1e9+10,maxm = (1 << 18)+10;
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
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n >= 2600){
        cout << 3000;
        return 0;
    }
    if (n >= 2400){
        cout << 2600;
        return 0;
    }
    if (n >= 2300){
        cout << 2400;
        return 0;
    }
    if (n >= 2100){
        cout << 2300;
        return 0;
    }
    if (n >= 1900){
        cout << 2100;
        return 0;
    }
    if (n >= 1600){
        cout << 1900;
        return 0;
    }
    if (n >= 1400){
        cout << 1600;
        return 0;
    }
    if (n >= 1200){
        cout << 1400;
        return 0;
    }
    cout << 1200;
}
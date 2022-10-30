#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const long long int N = 1e5+20,mod = 998244353,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int main(){
 //   ios :: sync_with_stdio(0); cin.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
    int sa = 1,sb = 2,sc = 3;
    if (a > c){
        swap(sa,sc);
        swap(a,c);
    }
    if (a > b){
        swap(sa,sb);
        swap(a,b);
    }
    if (b > c){
        swap(sc,sb);
        swap(c,b);
    }
    cout << "First" << endl;
    cout << 2*c-a-b << endl;
    int x;
    cin >> x;
    if (x == sa){
        cout << c-b << endl;
        return 0;
    }
    if (x == sb){
        cout << c-a << endl;
        return 0;
    }
    cout << 3*(2*c-a-b) << endl;
    cin >> x;
    if (x == sb)
        cout << 3*c-2*a-b << endl;
    else
        cout << 3*c-a-2*b << endl;
    return 0;
}
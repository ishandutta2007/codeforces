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
typedef pair<long double,long double> pld;
const long long int N = 3e5+10,mod = 1e9+7,inf = 1e18,sq = 65,fx = 98765431;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        if (!a[i]) cnt++;
    }
    if (a[n-1] == 1){
        cout << "NO";
        return 0;
    }
    if (cnt == 1){
        cout << "YES" << endl;
        rep(i,0,n-1) cout << a[i] << "->";
        cout << 0;
        return 0;
    }
    if (a[n-2] == 1){
        cout << "YES" << endl;
        rep(i,0,n-1)
            cout << a[i] << "->"; 
        cout << 0;
        return 0;
    }
    if (cnt == 2){
        cout << "NO";
        return 0;
    }
    int ind = -1;
    repr(i,n-3,0){
        if (!a[i]){
            ind = i;
            break;
        }
    }
    cout << "YES" << endl;
    rep(i,0,ind)
        cout << a[i] << "->";
    rep(i,ind,n-2)
        cout << '(' << a[i] << "->";
    cout << 0;
    rep(i,ind,n-2) cout << ')';
    cout << "->" << 0;
}
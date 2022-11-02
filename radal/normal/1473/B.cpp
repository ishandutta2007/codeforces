#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e16;
const long double eps = 0.0001;
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        string s,t;
        cin >> s >> t;
        if (s.size() > t.size()) swap(s,t);
        int sz = s.size(),sz2=t.size();
        int lc = lcm(sz,sz2);
        string S="",T="";
        rep(i,0,lc/sz) S += s;
        rep(i,0,lc/sz2) T+=t;
        if (T != S) cout << -1 << endl;
        else cout << S << endl;
    }
    return 0;
}
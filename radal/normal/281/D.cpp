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
const int N = 1e5+20,mod = 998244353,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
int n;
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n)
        cin >> a[i];
    stack<int> st;
    int ans = 0;
    rep(i,0,n){
        while (!st.empty() && st.top() < a[i]) st.pop();
        if (!st.empty()) ans = max(a[i]^st.top(),ans);
        st.push(a[i]);
    }
    while (!st.empty()) st.pop();
    repr(i,n-1,0){
        while (!st.empty() && st.top() < a[i]) st.pop();
        if (!st.empty()) ans = max(a[i]^st.top(),ans);
        st.push(a[i]);
    }
    cout << ans;
}
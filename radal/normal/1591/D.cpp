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
typedef pair<ll,ll> pll;
const long long int N = 5e5+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod)return a+b-mod;
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
int a[N];
int fen[N],n;
inline void upd (int l){
    for(; l <= n; l |= (l+1)){
        fen[l]++;
    }
}
inline int que(int l){
    int sum = 0;
    for(; l >= 0; l =(l&(l+1))-1){
        sum += fen[l];
    }
    return sum;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        cin >> n;
        bool f = 0;
        set<int> st;
        rep(i,0,n){
            cin >> a[i];
            if (!f && st.find(a[i]) != st.end()){
                f = 1;
            }
            else if (!f) st.insert(a[i]);
        }
        if (f){
            cout << "YES" << endl;
            st.clear();
            continue;
        }
        ll inv = 0;
        repr(i,n-1,0){
            inv += que(a[i]-1);
            upd(a[i]);
        }
        rep(i,0,n+1) fen[i] = 0;
        cout << ((inv&1) ? "NO" : "YES") << endl;
    }
}
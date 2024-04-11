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
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e18+10,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
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
vector<int> ind[N];
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            ind[a[i]].pb(i);
        }
        rep(i,0,n+1) reverse(ind[a[i]].begin(),ind[a[i]].end());
        vector<int> ans;
        set<int> st;
        rep(i,0,n){
            int mex = 0;
            st.insert(a[i]);
            if (!a[i]) mex++;
            ind[a[i]].pop_back();
            while (!ind[mex].empty()){
                i++;
                st.insert(a[i]);
                ind[a[i]].pop_back();
                while (st.find(mex) != st.end()) mex++;
            }
            ans.pb(mex);
            st.clear();
        }
        cout << ans.size() << endl;
        for (int u : ans) cout << u << ' ';
        cout << endl;
    }
}
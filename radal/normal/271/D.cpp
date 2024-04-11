#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 1e5+20,mod = 1e9+7,inf=1e18,cst = 98765431,mod2 = 999999937;
inline int mkay(int a,int b,int f = 1){
    if (f != 1){
        if (a+b < mod2) return a+b;
        return a+b-mod2;
    }
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
bool mark[N]; 
int po[N][2];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    string s,t;
    int n,k;
    cin >> s >> t >> k;
    n = s.size();
    rep(i,0,26) mark[i] = (t[i] == '0');
    set<pll> st;
    po[0][0] = 1;
    po[0][1] = 1;
    rep(i,1,n+1){
        po[i][0] = 1ll*cst*po[i-1][0]%mod;
        po[i][1] = 1ll*cst*po[i-1][1]%mod2;
    }
    rep(l,0,n){
        int t = 0;
        int g = 0,g2 = 0;
        rep(r,l,n){
            if (mark[s[r]-'a']) t++;
            if (t > k) break;
            g = mkay(g,1ll*(s[r]-'a'+1)*po[r-l][0]%mod);
            g2 = mkay(g2,1ll*(s[r]-'a'+1)*po[r-l][1]%mod2,2);
            st.insert({g,g2});
        }
    }
    cout << st.size();
}
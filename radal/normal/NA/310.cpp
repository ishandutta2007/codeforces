#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1);
}
ll dp[N][100],fa[20],po[20];
short int cn[10];
int main(){
    string s;
    int m,sz,sz2;
    cin >> s >> m;
    sz = s.size();
    rep(i,0,sz) cn[s[i]-'0']++;
    fa[0] = 1;
    po[0] = 1;
    rep(i,1,sz+1){
        fa[i] = fa[i-1]*i;
        po[i] = po[i-1]*10;
    }
    dp[0][0] = 1;
    int g = (1 << sz);
    for(ll i = 1; i < g; i++){
        string t="";
        ll u = i;
        while(u){
            if (u&1) t = '1'+t;
            else t = '0'+t;
            u >>= 1;
        }
        sz2 = t.size();
        while (sz2 < sz){
            t = '0'+t;
            sz2++;
        }
        int cnt = __builtin_popcountll(i);
        rep(j,0,m){
            rep(k,0,sz2){
                if (t[k] == '0') continue;
                if (cnt == sz && s[k] == '0') continue;
                u = (s[k]-'0')*po[cnt-1];
                u %= m;
                u = j-u;
                if (u < 0) u += m;
                dp[i][j] += dp[i-(1 << (sz-1-k))][u];
            }
        }
    }
    g--;
    rep(i,0,10) dp[g][0] /= fa[cn[i]];
    cout << dp[g][0];
}
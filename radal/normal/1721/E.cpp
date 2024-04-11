#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,base = 271;
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

map<int,int> ans;
int z[N];
void solve(){
    string s;
    cin >> s;
    int n = s.size(),l = 0,r = 0;
    rep(i,1,n){
        if (i <= r)
            z[i] = min(z[i-l],r-i+1);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if  (i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
        if (i+z[i] != n) continue;
        int hsh = 0;
        rep(j,z[i],z[i]+10){
            if (j >= n) break;
            hsh = 1ll*base*hsh%mod;
            hsh += s[j]-'a'+1;
            if (hsh >= mod) hsh -= mod;
            ans[hsh] = max(ans[hsh],j+1);
        }
    }
    int q;
    cin >> q;
    while (q--){
        string t;
        cin >> t;
        int m = t.size();
        int hsh = 0;
        rep(i,0,m){
            hsh = 1ll*base*hsh%mod;
            hsh += t[i]-'a'+1;
            int cur = 0;
            if (ans[hsh]) cur = ans[hsh];
            repr(j,i,0){
                bool fl = 1;
                rep(k,j,i+1){
                    if (k-j >= n){
                        fl = 0;
                        break;
                    }
                    if (s[k-j] != t[k]){
                        fl = 0;
                        break;
                    }
                }
                if (fl) cur = max(cur,i-j+1);
            }
            rep(j,1,m+1){
                if (j >= n) break;
                if (z[j]+j != n) continue;
                int nw = z[j],po = 0;
                bool fl = 1;
                while (nw < n && po <= i){
                    if(s[nw] != t[po]){
                        fl = 0;
                        break;
                    }
                    nw++;
                    po++;
                }
                if (!fl) continue;
                if (po > i){
                    cur = max(cur,z[j]+i+1);
                    continue;
                }
                rep(x,po,i+1){
                    if (t[x-po] != t[x]){
                        fl = 0;
                        break;
                    }
                }
                if (!fl) continue;
                cur = max(cur,z[j]+i+1);
            }
            cout << cur << ' ';
        }
        cout << endl;
    }
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
 //   cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
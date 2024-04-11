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
const long long int N = 1e4+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
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
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        ll a,s;
        cin >> a >> s;
        string t = "",t2 = "";
        ll v = a;
        while(v){
            t = char('0'+v%10)+t;
            v /= 10;
        }
        v = s;
        while (v){
            t2 = char('0'+v%10)+t2;
            v /= 10;
        }
        string ans = "";
        int n = t.size(),m = t2.size();
        int p1 = m-1;
        repr(i,n-1,0){
            if (p1 < 0){
                p1 = -3;
                break;
            }
            if (t2[p1] >= t[i]){
                ans = char(t2[p1]-t[i]+'0')+ans;
                p1--;
                continue;
            }
            if (p1 < 1 || t2[p1-1] != '1'){
                p1 = -3;
                break;
            }
            ans = char(t2[p1]-t[i]+10+'0')+ans;
            p1 -= 2;
        }
        if (p1 < -1){
            cout << -1 << endl;
            continue;
        }
        repr(i,p1,0)
            ans = t2[i]+ans;
        p1 = 0;
        while (ans[p1] == '0') p1++;
        rep(i,p1,int(ans.size())) cout << ans[i];
        cout << endl;
    }
}
#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e18+10,sq = 32000;
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
ll l[N],r[N],c[N];
ll mi[N],mx[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1; 
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll ans1 = inf,ans2 = inf,ans3 = inf;
        rep(i,0,n){
            cin >> l[i] >> r[i] >> c[i];
            if (!i){
                mi[0] = l[i];
                mx[0] = r[i];
            }
            else{
                mx[i] = max(mx[i-1],r[i]);
                mi[i] = min(mi[i-1],l[i]);
            }
        }
        cout << c[0] << endl;
        ans1 = c[0];
        ans2 = c[0];
        ans3 = c[0];
        rep(i,1,n){
            if (mi[i] == mi[i-1]){
                if (l[i] == mi[i]) ans1 = min(ans1,c[i]);
            }
            if (mi[i] < mi[i-1]){
                ans1 = c[i];
                ans3 = inf;
            }
            if (mx[i] == mx[i-1] && r[i] == mx[i])
                ans2 = min(c[i],ans2);
            if (mx[i] > mx[i-1]){
                ans2 = c[i];
                ans3 = inf;
            }
            if (l[i] == mi[i] && r[i] == mx[i]) ans3 = min(ans3,c[i]);
            cout << min(ans3,ans1+ans2) << endl;
        }
    }
}
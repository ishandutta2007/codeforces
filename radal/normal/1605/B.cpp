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
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 5e3+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 1e3+10;
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
vector<int> ve[N];
int pre[N],suf[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T; 
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        bool f = 0;
        rep(i,0,n){
            if (i < n-1 && s[i] == '1' && s[i+1] =='0') f=  1;
            if (s[i] == '1') pre[i] = 1,suf[i] = 0;
            else suf[i] = 1,pre[i] = 0;
            if (i) pre[i]+=pre[i-1],suf[i] += suf[i-1];
        }
        if (!f){
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
        vector<int> ve;
        int t = 0;
        rep(i,0,n){
            if (s[i] == '1'){
                if (pre[i]-1 < suf[n-1]-suf[i]){
                    ve.pb(i+1);
                    t++;
                }
            }
        }
        rep(i,0,n)
            if (s[i] == '0')
                if (n-t <= i+pre[n-1]-pre[i]) ve.pb(i+1);
        sort(ve.begin(),ve.end());
        cout << ve.size() << ' ';
        for (int u : ve) cout << u << ' ';
        cout << endl;
    }
}
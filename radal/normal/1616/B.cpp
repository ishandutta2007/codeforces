#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const long long int N = 7e5+20,mod = 1e9+7,inf = 1e9+10,sq = 400;
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
        int n;
        string s;
        cin >> n >> s;
        bool f = 0,ok = 0;
        rep(i,0,n-1){
            if (s[i] < s[i+1] || (!f && s[i] == s[i+1])){
                rep(j,0,i+1){
                    cout << s[j];
                }
                repr(j,i,0)
                    cout << s[j];
                cout << endl;
                ok = 1;
                break;
            }
            else if (s[i] > s[i+1]) f = 1;
        }
        if (!ok){
            cout << s;
            reverse(s.begin(),s.end());
            cout << s << endl;
        }
    }
}
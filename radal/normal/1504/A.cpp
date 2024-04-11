#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> s;
        n = s.size();
        bool f = 0;
        rep(i,0,n) if (s[i] != 'a') f = 1;
        if (!f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        string t = "";
        f = 0;
        rep(i,0,n){
            if (f){
                t+=s[i];
                continue;
            }
            if (s[n-i-1] != 'a'){
                t+='a';
                t+=s[i];
                f = 1;
                continue;
            }
            t += s[i];
        }
        cout << t << endl;
    }
    return 0;
}
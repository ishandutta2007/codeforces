#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
int main(){
    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int n;
        cin >> n;
        cin >> s;
        if (n < 11){
            cout << "NO" << endl;
            continue;
        }
        bool f = 0;
        rep(i,0,n-10){
            if (s[i] == '8'){
                f = 1;
                break;
            }
            
        }
        cout << ((f) ? "YES" : "NO") << endl;

    }
    return 0;
}
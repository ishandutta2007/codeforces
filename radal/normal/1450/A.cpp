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
const long long int N=5e1+2,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        int a[n];
        rep(i,0,n){
            a[i] = int(s[i])-int('a');
        }
        sort(a,a+n);
        rep(i,0,n) cout << char(a[i]+int('a'));
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = 1e6+10;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[3];
int main(){
    string s;
    int n;
    cin >> s;
    n = s.size();
    rep(i,1,n){
        if (int(s[i]) < int(s[i-1])){
            cout << "NO";
            return 0;
        }
    }
    rep(i,0,n){
        if (s[i] -'a' > 2){
            cout << "NO" << endl;
            return 0;
        }
        a[s[i]-'a']++;
    }
    debug(a[0]);
    debug(a[2]);
    debug(a[1]);
    if (!a[0] || !a[1] || (a[2] != a[0] && a[2] != a[1])) cout << "NO";
    else cout << "YES";
    return 0;
}
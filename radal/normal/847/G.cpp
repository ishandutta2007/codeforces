#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=1e5+30,mod = 1e9+7,inf=1e18;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll n; 
    cin >> n;
    string s[n];
    rep(i,0,n){
        cin >> s[i];
    }
    ll ans=0;
    rep (j,0,7){
        ll cnt=0;
        rep (i,0,n){
            if (s[i][j] == '1') cnt++;
        }
        ans = max(cnt,ans);
    }
    cout << ans;
    return 0;

}
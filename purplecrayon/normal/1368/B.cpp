#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

ll mult(vector<ll>& v){
    ll res=1;
    for (auto it : v) res *= it;
    return res;
}
void solve(){
    ll n; cin >> n;
    //10 letters
    string s = "codeforces";
    vector<ll> cnt(10, 0); int i = 0;
    while (mult(cnt) < n){
        cnt[i]++; i = (i+1)%sz(s);
    }
    for (int i = 0; i < sz(s); i++) for (int j = 0; j < cnt[i]; j++) cout << s[i];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}
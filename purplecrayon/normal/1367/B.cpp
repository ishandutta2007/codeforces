#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int o = 0, e = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if ((i%2==0)&&(a[i]%2==1)) e++;
        else if ((i%2==1)&&(a[i]%2==0)) o++;
    }
    if (e != o) cout << "-1\n";
    else cout << o << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
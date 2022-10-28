#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 60, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n, x; cin >> n >> x; --x;
    string p1 = "Ayush\n", p2 = "Ashish\n";
    vector<int> deg(n, 0);
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        deg[a]++, deg[b]++;
    }
    if ((n==1) || (deg[x] == 1) || (n%2 == 0)) cout << p1;
    else cout << p2;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}
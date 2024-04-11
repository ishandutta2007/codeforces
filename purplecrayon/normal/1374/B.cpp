#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 5e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    ll n; cin >> n;
    ll p2 = 0, p3 = 0;
    while (n%2 == 0) n/=2, p2++;
    while (n%3 == 0) n/=3, p3++;
    if (n!=1 || p2 > p3) { cout << "-1\n"; return; }
    cout << p3+(p3-p2) << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}
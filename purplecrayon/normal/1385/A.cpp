#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

void solve(){
    int x, y, z;
    cin >> x >> y >> z; vector<int> v{x, y, z}; sort(v.begin(), v.end());
    if (v[1] != v[2]) cout << "NO\n";
    else {
        cout << "YES\n" << v[0] << " " << v[0] << " " << v[2] << "\n";
    }
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}
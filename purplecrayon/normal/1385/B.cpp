#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

void solve(){
    int n; cin >> n;
    vector<int> v; for (int i = 0, a; i < 2*n; i++) cin >> a, v.push_back(a);
    set<int> s; vector<int> ans;
    for (int i = 0; i < (int)v.size(); i++){
        if (s.count(v[i])) continue;
        ans.push_back(v[i]); s.insert(v[i]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}
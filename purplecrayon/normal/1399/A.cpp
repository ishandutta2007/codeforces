#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

void solve(){
    int n; cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; i++){
        int c; cin >> c; a.insert(c);
    }
    while (a.size() > 1){
        auto c = a.begin(); a.erase(a.begin());
        auto it = a.lower_bound(*c);
        if (it == a.end() || (*it) > (*c)+1){cout << "NO" << "\n"; return; }
    }
    cout << "YES" << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
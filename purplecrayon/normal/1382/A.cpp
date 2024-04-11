#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e3+10, ALP=27;

void solve(){
    int n, m; cin >> n >> m;
    set<int> s;
    for (int i = 0, a; i < n; i++) cin >> a, s.insert(a);
    bool bad = 1;
    for (int i = 0, b; i < m; i++){
        cin >> b;
        if (s.count(b) && bad){
            cout << "YES\n1 " << b << "\n"; bad = 0;
        }
    }
    if (bad) cout << "NO\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
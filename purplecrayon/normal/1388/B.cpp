#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;

void solve(){
    int n; cin >> n;
    int x = (n + 3) / 4;
    for (int i = 0; i < n - x; ++i) {
        cout << 9;
    }
    for (int i = 0; i < x; ++i) {
        cout << 8;
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
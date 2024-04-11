#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

void solve(){
    int n;  cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) cout << n << "\n";
    else cout << "1\n";
}
int main () {
     ios::sync_with_stdio (false); cin.tie (0);
     int t; cin >> t; while (t--) solve ();
}
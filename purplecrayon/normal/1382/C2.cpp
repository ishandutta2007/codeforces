#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10, ALP=27;

int a[MAXN];
bool dp[MAXN][2];

void solve(){
    int n; string a, b; cin >> n >> a >> b;
    vector<int> ops1, ops2;
    a += '0'; b += '0';
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) ops1.push_back(i);
        if(b[i] != b[i - 1]) ops2.push_back(i);
    }
    ops1.insert(ops1.end(), ops2.rbegin(), ops2.rend());
    cout << ops1.size();
    for(int x : ops1) {
        cout << ' ' << x;
    }
    cout << '\n';
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
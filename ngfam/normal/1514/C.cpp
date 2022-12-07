#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n;
int f[130][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> factors;

    cin >> n;    
    
    int prod = 1;

    vector<int> ans;
    for (int i = 1; i < n; ++i) {
        if (__gcd(i, n) == 1) ans.push_back(i), prod = 1ll * i * prod % n;
    }

    cout << ans.size() - (prod != 1) << endl;
    for(int x : ans) if(prod == 1 || x != prod) cout << x << " ";

    return 0;
}
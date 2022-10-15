#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> v, int r) {
    vector<int> a;
    for (auto x : v) if (x != r) a.push_back(x);
    auto b = a;
    reverse(b.begin(), b.end());
    return a == b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int a = 0;
        int b = n-1;
        while (a < b) {
            if (v[a] != v[b]) break;
            a++; b--;
        }
        bool ok = check(v,v[a]) || check(v,v[b]);
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
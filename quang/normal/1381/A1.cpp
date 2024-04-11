#include <bits/stdc++.h>

using namespace std;

vector<int> get(string &a) {
    vector<int> res;
    int need = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        if (need == a[i] - '0') {
            continue;
        }
        need ^= 1;
        res.push_back(i + 1);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> res = get(a);
        vector<int> res1 = get(b);
        cout << res.size() + res1.size() << ' ';
        for (int u : res) {
            cout << u << ' ';
        }
        reverse(res1.begin(), res1.end());
        for (int u : res1) cout << u << ' ';
            cout << '\n';
    }   
    return 0;
}
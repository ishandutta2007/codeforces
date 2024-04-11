#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int n;

vector<int> ask(int x) {
    cout << "? " << x + 1 << endl;
    vector<int> res(n);
    for (int i = 0; i < n; i++) cin >> res[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    vector<int> d = ask(0);
    vector<int> c(2);
    for (int i = 0; i < n; i++) c[d[i] % 2]++;
    int k = c[1] < c[0] ? 1 : 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        if (d[i] % 2 == k) {
            vector<int> dd = i == 0 ? d : ask(i);
            for (int j = 0; j < n; j++) {
                if (dd[j] == 1) res.push_back({i + 1, j + 1});
            }
        }
    }
    cout << "!\n";
    for (auto p : res) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>

#define long long long int

using std::vector;
using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].first--;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());

    vector<vector<int>> ans;
    vector<bool> z(n);
    for (int i = 0; i < n; i++) {
        if (!z[i]) {
            int j = i;
            vector<int> p;
            while (!z[j]) {
                p.push_back(j + 1);
                z[j] = true;
                j = a[j].second;
            }
            ans.push_back(p);
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.size();
        for (auto x : p) {
            cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}
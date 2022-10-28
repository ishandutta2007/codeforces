#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<string, vector<int>> mp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                string word;
                cin >> word;
                mp[word].push_back(i);
            }
        }

        array<int, 3> points;
        points.fill(0);

        for (auto &[s, v] : mp) {
            if (v.size() == 1) {
                points[v[0]] += 3;
            } else if (v.size() == 2) {
                points[v[0]] += 1;
                points[v[1]] += 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            cout << points[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
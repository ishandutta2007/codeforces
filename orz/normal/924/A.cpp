#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> table(static_cast<unsigned int>(n), vector<char>(static_cast<unsigned int>(m)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    vector<unordered_set<int>> columns(static_cast<unsigned int>(n)), rows(static_cast<unsigned int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == '#') {
                columns[i].insert(j);
                rows[j].insert(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool diff = true, eq = true;
            for (int t : columns[i]) {
                if (columns[j].count(t) == 0) {
                    eq = false;
                } else {
                    diff = false;
                }
            }
            for (int t : columns[j]) {
                if (columns[i].count(t) == 0) {
                    eq = false;
                } else {
                    diff = false;
                }
            }
            if (!diff && !eq) {
                cout << "No\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool diff = true, eq = true;
            for (int t : rows[i]) {
                if (rows[j].count(t) == 0) {
                    eq = false;
                } else {
                    diff = false;
                }
            }
            for (int t : rows[j]) {
                if (rows[i].count(t) == 0) {
                    eq = false;
                } else {
                    diff = false;
                }
            }
            if (!diff && !eq) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;

}
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, string>>> reg(m);

    for (int i = 0; i < n; i++) {
        string name;
        int score, r;
        cin >> name >> r >> score;
        r--;
        reg[r].push_back(make_pair(score, name));
    }

    for (int i = 0; i < m; i++) {
        sort(reg[i].begin(), reg[i].end());
        int k = reg[i].size();
        if (k > 2 && reg[i][k - 3].first == reg[i][k - 2].first) {
            cout << "?" << endl;
        } else {
            cout << reg[i][k - 2].second << " " << reg[i][k - 1].second << endl;
        }
    }

    return 0;
}
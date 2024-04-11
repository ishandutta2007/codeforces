#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

map<int, int> frequency;

bool works(int n, int m, int r, int c) {
    unordered_map<int, int> my_freq;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int d = abs(i - r) + abs(j - c);
            my_freq[d]++;

            if (my_freq[d] > frequency[d])
                return false;
        }

    for (auto it = frequency.begin(); it != frequency.end(); it++)
        if (it->second != my_freq[it->first])
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int number;
        cin >> number;
        frequency[number]++;
    }

    int maximum = frequency.rbegin()->first;
    int distance = maximum + 1;

    for (auto it = frequency.begin(); it != frequency.end(); it++)
        if (it->second < 4 * it->first) {
            distance = it->first;
            break;
        }

    vector<tuple<int, int, int, int>> candidates;

    for (int n = 1; n * n <= T; n++)
        if (T % n == 0) {
            int m = T / n;
            candidates.push_back(make_tuple(n, m, distance - 1, maximum - (n - distance)));
            candidates.push_back(make_tuple(m, n, distance - 1, maximum - (m - distance)));
        }

    for (auto t : candidates) {
        int n, m, r, c;
        tie(n, m, r, c) = t;

        if (works(n, m, r, c)) {
            cout << n << ' ' << m << '\n';
            cout << r + 1 << ' ' << c + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
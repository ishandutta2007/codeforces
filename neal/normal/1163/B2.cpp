#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> freq;
    multiset<int> counts;
    int best = 0;

    for (int i = 1; i <= N; i++) {
        int u;
        cin >> u;

        if (freq[u] > 0)
            counts.erase(counts.find(freq[u]));

        freq[u]++;
        counts.insert(freq[u]);

        bool streak = false;

        if (counts.size() == 1) {
            streak = true;
        } else {
            if (*counts.begin() + 1 == *counts.rbegin()) {
                auto it = counts.rbegin();
                it++;

                if (*it == *counts.begin())
                    streak = true;
            }

            if (*counts.begin() == 1) {
                auto it = counts.begin();
                it++;

                if (*it == *counts.rbegin())
                    streak = true;
            }
        }

        if (streak)
            best = max(best, i);
    }

    cout << best << '\n';
}
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

    int N, M;
    cin >> N >> M;
    map<int, bool> taken;
    vector<int> trees(N);

    for (int &t : trees) {
        cin >> t;
        taken[t] = true;
    }

    sort(trees.begin(), trees.end());
    set<pair<int, int>> candidates;

    for (int t : trees) {
        if (!taken[t - 1]) {
            candidates.emplace(1, t - 1);
            taken[t - 1] = true;
        }

        if (!taken[t + 1]) {
            candidates.emplace(1, t + 1);
            taken[t + 1] = true;
        }
    }

    long long total = 0;
    vector<int> people;

    for (int i = 0; i < M; i++) {
        pair<int, int> best = *candidates.begin();
        candidates.erase(candidates.begin());
        int dist = best.first, x = best.second;
        total += dist;
        people.push_back(x);

        if (!taken[x - 1]) {
            candidates.emplace(dist + 1, x - 1);
            taken[x - 1] = true;
        }

        if (!taken[x + 1]) {
            candidates.emplace(dist + 1, x + 1);
            taken[x + 1] = true;
        }
    }

    cout << total << '\n';

    for (int i = 0; i < M; i++)
        cout << people[i] << (i < M - 1 ? ' ' : '\n');
}
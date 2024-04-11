#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> powers;
vector<pair<int, int>> pairs;
vector<bool> available;

int paired_with(int x) {
    for (int i = 0; i < M; i++)
        if (pairs[i].first == x)
            return pairs[i].second;
        else if (pairs[i].second == x)
            return pairs[i].first;

    return -1;
}

int best_pair() {
    int best_pick = -1, best_diff = -1;

    for (int i = 0; i < M; i++) {
        int a = pairs[i].first, b = pairs[i].second;

        if (available[a] && available[b] && powers[a] - powers[b] > best_diff) {
            best_diff = powers[a] - powers[b];
            best_pick = a;
        }
    }

    return best_pick;
}

int maximum_pick() {
    int best_pick = -1;

    for (int i = 1; i <= 2 * N; i++)
        if (available[i] && (best_pick == -1 || powers[i] > powers[best_pick]))
            best_pick = i;

    return best_pick;
}

void pick(int x) {
    cout << x << endl;
    available[x] = false;
}

int main() {
    cin >> N >> M;
    powers.resize(2 * N + 1);

    for (int i = 1; i <= 2 * N; i++)
        cin >> powers[i];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (powers[a] < powers[b])
            swap(a, b);

        pairs.emplace_back(a, b);
    }

    available.assign(2 * N + 1, true);
    int turn, previous = -1;
    cin >> turn;

    for (int iter = 0; iter < 2 * N; iter++) {
        if (turn == 1) {
            int p = paired_with(previous);

            if (p >= 0 && available[p]) {
                pick(p);
            } else {
                p = best_pair();

                if (p >= 0 && available[p]) {
                    pick(p);
                } else {
                    p = maximum_pick();
                    assert(p >= 0);
                    pick(p);
                }
            }
        } else {
            cin >> previous;
            available[previous] = false;
        }

        turn = turn == 1 ? 2 : 1;
    }
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int CUTOFF = 550;

int N, Q;
vector<vector<int>> rides;

bool consistent() {
    vector<int> location(N);
    vector<vector<pair<int, int>>> small_locations(N);

    for (int r = 0; r < Q; r++)
        if (rides[r].size() > CUTOFF) {
            fill(location.begin(), location.end(), -1);

            for (int i = 0; i < (int) rides[r].size(); i++)
                location[rides[r][i]] = i;

            for (int i = 0; i < Q; i++) {
                int previous = N;

                for (int x : rides[i]) {
                    if (location[x] == -1)
                        continue;

                    if (location[x] > previous + 1)
                        return false;

                    previous = location[x];
                }
            }
        } else {
            for (int i = 0; i < (int) rides[r].size() - 1; i++)
                small_locations[rides[r][i]].emplace_back(r, i);
        }

    vector<int> after(N, -1);

    for (int cross = 0; cross < N; cross++) {
        for (pair<int, int> &p : small_locations[cross]) {
            int r = p.first, index = p.second;
            int next = rides[r][index + 1];

            for (int i = index + 1; i < (int) rides[r].size(); i++) {
                int &saved = after[rides[r][i]];

                if (saved != -1 && saved != next)
                    return false;

                saved = next;
            }
        }

        // Reset everything to -1.
        for (pair<int, int> &p : small_locations[cross]) {
            int r = p.first, index = p.second;

            for (int i = index + 1; i < (int) rides[r].size(); i++)
                after[rides[r][i]] = -1;
        }
    }

    return true;
}

void solve_case() {
    scanf("%d %d", &N, &Q);
    rides.assign(Q, {});

    for (int i = 0; i < Q; i++) {
        int k;
        scanf("%d", &k);
        rides[i].resize(k);

        for (int &c : rides[i]) {
            scanf("%d", &c);
            c--;
        }
    }

    puts(consistent() ? "Robot" : "Human");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}
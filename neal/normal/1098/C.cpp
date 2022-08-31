#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long N, S;
vector<int> children, parent, level;

long long minimum_sum(int branching) {
    children.assign(N, 0);
    parent.assign(N, -1);
    level.assign(N, 1);
    long long total = 1;
    int current = 0;

    for (int i = 1; i < N; i++) {
        while (children[current] >= branching)
            current++;

        parent[i] = current;
        level[i] = level[current] + 1;
        total += level[i];
        children[current]++;
    }

    // cerr << "minimum_sum(" << branching << ") = " << total << endl;
    return total;
}

int main() {
    scanf("%lld %lld", &N, &S);
    assert(minimum_sum(1) == N * (N + 1) / 2);
    assert(minimum_sum(N - 1) == 2 * N - 1);

    if (S < 2 * N - 1 || S > N * (N + 1) / 2) {
        puts("No");
        return 0;
    }

    int low = 0, high = N - 1;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (minimum_sum(mid) >= S)
            low = mid;
        else
            high = mid - 1;
    }

    long long total = minimum_sum(low);
    int branching = low + 1;
    vector<vector<int>> levels(N + 1);

    for (int i = 0; i < N; i++)
        levels[level[i]].push_back(i);

    int search_level = 0;

    for (int i = N - 1; i > 0 && total > S; i--) {
        // Find i a new parent.
        children[parent[i]]--;
        total -= level[i];

        while (true) {
            bool found = false;

            while (!levels[search_level].empty()) {
                int back = levels[search_level].back();

                if (level[back] != search_level || children[back] >= branching) {
                    levels[search_level].pop_back();
                } else {
                    found = true;
                    break;
                }
            }

            if (found)
                break;

            search_level++;
        }

        int current = levels[search_level].back();

        if (total + level[current] + 1 < S) {
            for (int x = 0; x < N; x++)
                if (x != i && children[x] < branching && total + level[x] + 1 == S) {
                    current = x;
                    break;
                }
        }

        // cerr << "Attach " << i << " to " << current << endl;
        parent[i] = current;
        children[current]++;
        level[i] = level[current] + 1;
        total += level[i];
        levels[level[i]].push_back(i);
    }

    assert(total == S);
    puts("Yes");

    for (int i = 1; i < N; i++)
        printf("%d%c", parent[i] + 1, i < N - 1 ? ' ' : '\n');
}
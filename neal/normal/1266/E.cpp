#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, Q;
vector<int> A;
vector<map<int, int>> milestones;
vector<int> free_cnt;
long long saved = 0;

void change_free(int index, int change) {
    if (change > 0) {
        free_cnt[index]++;

        if (free_cnt[index] <= A[index])
            saved++;
    } else {
        free_cnt[index]--;

        if (free_cnt[index] < A[index])
            saved--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    long long A_sum = 0;

    for (int &a : A) {
        cin >> a;
        A_sum += a;
    }

    milestones.assign(N, {});
    free_cnt.assign(N, 0);
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int s, t, u;
        cin >> s >> t >> u;
        s--; u--;

        if (milestones[s].find(t) != milestones[s].end()) {
            change_free(milestones[s][t], -1);
            milestones[s].erase(t);
        }

        if (u >= 0) {
            milestones[s][t] = u;
            change_free(u, +1);
        }

        cout << A_sum - saved << '\n';
    }
}
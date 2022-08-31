#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5e5 + 5;
const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, K, N, S;
    cin >> M >> K >> N >> S;
    vector<int> A(M);
    vector<int> B(S);

    for (int i = 0; i < M; i++)
        cin >> A[i];

    for (int i = 0; i < S; i++)
        cin >> B[i];

    vector<int> needed(MAX, 0);
    int satisfied = 0;

    for (int b : B)
        needed[b]++;

    int best = INF;
    int best_beginning = -1, best_start = -1, best_end = -1;

    for (int i = 0, j = 0; i < M; i++) {
        while (j < M && satisfied < S) {
            if (needed[A[j]] > 0)
                satisfied++;

            needed[A[j]]--;
            j++;
        }

        if (satisfied >= S) {
            int length = min(j - i, K);
            int remove = j - i - length;
            int beginning = 0;

            if (i / K != (i + length) / K) {
                beginning += (i + length) % K;
                remove += beginning;
            }

            if (remove < best) {
                best = remove;
                best_beginning = beginning;
                best_start = i;
                best_end = j;
            }
        }

        needed[A[i]]++;

        if (needed[A[i]] > 0)
            satisfied--;
    }

    if (M - best < N * K) {
        cout << -1 << '\n';
        return 0;
    }

    cout << best << '\n';
    vector<int> to_remove;

    for (int i = 0; i < best_beginning; i++)
        to_remove.push_back(i);

    needed.assign(MAX, 0);

    for (int b : B)
        needed[b]++;

    for (int i = best_start; i < best_end; i++) {
        if (needed[A[i]] <= 0)
            to_remove.push_back(i);

        needed[A[i]]--;
    }

    // assert((int) to_remove.size() == best);

    for (int i = 0; i < best; i++)
        cout << to_remove[i] + 1 << (i < best - 1 ? ' ' : '\n');
}
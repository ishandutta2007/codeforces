#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct event {
    int type, p, x;
};

int N, Q;
vector<int> A;
vector<event> events;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    cin >> Q;
    events.resize(Q);
    vector<int> last_occurrence(N, -1);

    for (int q = 0; q < Q; q++) {
        event &ev = events[q];
        cin >> ev.type;

        if (ev.type == 1) {
            cin >> ev.p >> ev.x;
            ev.p--;
            last_occurrence[ev.p] = q;
        } else if (ev.type == 2) {
            cin >> ev.x;
        } else {
            assert(false);
        }
    }

    vector<int> suffix_max(Q + 1, 0);

    for (int q = Q - 1; q >= 0; q--)
        suffix_max[q] = max(suffix_max[q + 1], events[q].type == 2 ? events[q].x : 0);

    for (int i = 0; i < N; i++) {
        int balance = A[i];

        if (last_occurrence[i] >= 0)
            balance = events[last_occurrence[i]].x;

        balance = max(balance, suffix_max[last_occurrence[i] + 1]);
        cout << balance << (i < N - 1 ? ' ' : '\n');
    }
}
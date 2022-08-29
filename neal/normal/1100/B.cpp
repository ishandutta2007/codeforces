#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> freq;
int distinct;

void hold_round() {
    for (int i = 0; i < N; i++)
        if (--freq[i] == 0)
            distinct--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    freq.assign(N, 0);
    distinct = 0;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        a--;

        if (freq[a]++ == 0)
            distinct++;

        if (distinct == N) {
            hold_round();
            cout << '1';
        } else {
            cout << '0';
        }
    }

    cout << '\n';
}
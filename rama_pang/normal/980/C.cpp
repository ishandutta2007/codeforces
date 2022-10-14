#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> P;

void solve(int n, int tl, int tr) {
    for (int i = tl; i <= tr; i++) {

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> range(1000, -1);
    vector<int> ans(N);
    vector<int> freq(1000, 0);

    for (int i = 0; i < N; i++) {
        if (range[P[i]] != -1) {
            continue;
        }
        int key = max(0, P[i] - K + 1);
        int cnt = K;
        for (int j = P[i]; j >= max(0, P[i] - K + 1); j--) {
            if (range[j] != -1) {
                key = j + 1;
                if (P[i] - j <= K - freq[range[j]]) {
                    key = range[j];
                }
                break;
            }
        }
        for (int j = P[i]; j >= max(0, P[i] - K + 1); j--) {
            if (range[j] != -1) {
                break;
            }
            range[j] = key;
            freq[key]++;
            cnt--;
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i] = range[P[i]];
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAX = 5005;

int N;
int K[1000005];

int cnt[MAX];
int prime[MAX][MAX];
int highestPrime[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K[i];
        cnt[K[i]]++;
    }

    for (int i = 2; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            prime[i][j] += prime[i - 1][j];
        }
        int tmp = i;
        for (int j = 2; j * j <= tmp; j++) {
            while (tmp % j == 0) {
                prime[i][j]++;
                tmp /= j;
            }
        }
        if (tmp > 1) {
            prime[i][tmp]++;
        }
    }

    lint ans = 0;
    lint cur = 0;

    for (int i = 0; i < MAX; i++) {
        if (!cnt[i]) {
            highestPrime[i] = 1;
            continue;
        }
        highestPrime[i] = 1;
        for (int j = 0; j < MAX; j++) {
            ans += (lint) prime[i][j] * cnt[i];
            cur += (lint) prime[i][j] * cnt[i];
            if (prime[i][j]) {
                highestPrime[i] = j;
            }
        }
    }

    while (*max_element(highestPrime, highestPrime + MAX) > 1) {
        vector<int> freq(MAX, 0);
        for (int i = 0; i < MAX; i++) {
            freq[highestPrime[i]] += cnt[i];
        }
        auto best = max_element(begin(freq), end(freq)) - begin(freq);
        lint mx = freq[best];
        if (mx * 2 <= N) {
            break;
        }
        if (best == 1) {
            break;
        }
        cur -= mx;
        cur += (N - mx);
        ans = min(ans, cur);
        for (int i = 0; i < MAX; i++) {
            if (highestPrime[i] != best) {
                highestPrime[i] = 1;
            }
            if (highestPrime[i] == 1) {
                continue;
            }
            prime[i][highestPrime[i]]--;
            while (highestPrime[i] > 1 && prime[i][highestPrime[i]] == 0) {
                highestPrime[i]--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
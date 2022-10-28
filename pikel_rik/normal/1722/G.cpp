#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

        vector<int> answer(n);

        int j = 1;
        for (int i = 0; i < n; i += 2) {
            answer[i] = j++;
        }

        if (n % 2 == 0) {
            answer[n - 4] = (1 << 29) + rng() % (1 << 29);
            answer[n - 2] = 1 << 30;
        } else {
            answer[n - 3] = (1 << 29) + rng() % (1 << 29);
            answer[n - 1] = 1 << 30;
        }

        int even_xor = 0;
        for (int i = 0; i < n; i += 2) {
            even_xor ^= answer[i];
        }

        int odd_xor = 0;
        for (int i = 1; i < n; i += 2) {
            answer[i] = j++;
            odd_xor ^= answer[i];
        }

        if (n % 2 == 0) {
            odd_xor ^= answer[n - 1];
            answer[n - 1] = odd_xor ^ even_xor;
        } else {
            odd_xor ^= answer[n - 2];
            answer[n - 2] = odd_xor ^ even_xor;
        }

        for (int i = 0; i < n; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> A(N);
        int odd_string = 0;
        int bad = 0;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i].size() % 2 == 1) {
                odd_string++;
            } else {
                int one = 0, zer = 0;
                for (int j = 0; j < A[i].size(); j++) {
                    if (A[i][j] == '0') {
                        zer++;
                    } else {
                        one++;
                    }
                }
                if (!(one % 2 == 0 && zer % 2 == 0)) {
                    bad++;
                }
            }
        }
        if (odd_string > 0 || bad % 2 == 0) {
            cout << N << "\n";
        } else {
            cout << N - 1 << "\n";
        }
    }

}
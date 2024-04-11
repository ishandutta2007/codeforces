#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N, K;
    cin >> N >> K;

    vector<string> S(N);
    vector<lint> A(N);
    unordered_map<lint, int> cnt;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;

        lint hash = 0;
        for (int k = 0; k < K; k++) {
            hash *= 3;
            if (a[k] == 'S') {
                hash += 0;
            } else if (a[k] == 'E') {
                hash += 1;
            } else {
                hash += 2;
            }
        }
        

        A[i] = hash;
        S[i] = a;
        cnt[hash]++;
    }

    lint ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            cnt[A[i]]--;
            cnt[A[j]]--;
            lint search = 0;
            for (int k = 0; k < K; k++) {
                search *= 3;
                if (S[i][k] == S[j][k]) {
                    if (S[i][k] == 'S') {
                        search += 0;
                    } else if (S[i][k] == 'E') {
                        search += 1;
                    } else {
                        search += 2;
                    }
                } else if (S[i][k] != S[j][k]) {
                    char nw = S[i][k] ^ S[j][k] ^ 'S' ^ 'E' ^ 'T';
                    if (nw == 'S') {
                        search += 0;
                    } else if (nw == 'E') {
                        search += 1;
                    } else {
                        search += 2;
                    }
                }
            }

            ans += cnt[search];
            cnt[A[i]]++;
            cnt[A[j]]++;
        }
    }
    ans /= 6;
    cout << ans << "\n";
    return 0;
}
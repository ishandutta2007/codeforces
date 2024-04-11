#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 5e5 + 10, M = 10000;
int g[N];

void calc() {
    g[0] = 0;
    g[1] = 0;
    for (int i = 2; i < M; i++) {
        vector<bool> used(M);
        for (int j = 0; j + 2 <= i; j++) {
            int val = (g[j] ^ g[i - j - 2]);
            used[val] = 1;
        }
        int mex = 0;
        while (used[mex]) {
            mex++;
        }
        g[i] = mex;
    }
    for (int i = M; i < N; i++) {
        g[i] = g[i - 34];
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc();
    int t;
    cin >> t;
    while (t--) {
        int n, r = 0, b = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                r++;
            } else {
                b++;
            }
        }
        if (r > b) {
            cout << "Alice" << endl;
        } else if (r < b) {
            cout << "Bob" << endl;
        } else {
            int res = 0;
            for (int i = 0; i + 1 < n; i++) {
                if (s[i] != s[i + 1]) {
                    int j = i;
                    while (j + 1 < n && s[j] != s[j + 1]) {
                        j++;
                    }
                    res ^= g[j - i + 1];
                    i = j;
                }
            }
            if (res == 0) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
    }
    return 0;
}
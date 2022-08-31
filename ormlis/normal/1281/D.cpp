#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
ll MOD = 1e9 + 7;
ll sub(ll a, ll b) {
    if (a - b < 0) return a - b + MOD;
    return a - b;
}

ll add(ll a, ll b) {
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}
void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> arr(r, vector<int> (c));
    char a;
    int flag = 0, flag2 = 0;
    range(i, r) {
        range(j, c) {
            cin >> a;
            if (a == 'A') {
                flag2 = 1;
                arr[i][j] = 1;
            } else {
                flag = 1;
                arr[i][j] = 0;
            }
        }
    }
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    range(i, c) {
        c1 += arr[0][i];
        c2 += arr[r - 1][i];
    }
    range(i, r) {
        c3 += arr[i][0];
        c4 += arr[i][c - 1];
    }
    if(c1 == c || c2 == c || c3 == r || c4 == r) {
        if (flag) cout << 1;
        else cout << 0;
        return;
    }
    if(arr[0][0] || arr[r - 1][c - 1] || arr[0][c - 1] || arr[r - 1][0]) {
        cout << 2;
        return;
    }
    range(i, r) {
        int cur = 0;
        range(j, c) {
            cur += arr[i][j];
        }
        if (cur == c) {
            cout << 2;
            return;
        }
    }
    range(j, c) {
        int cur = 0;
        range(i, r) {
            cur += arr[i][j];
        }
        if (cur == r) {
            cout << 2;
            return;
        }
    }
    if (c1 || c2 || c3 || c4) {
        cout << 3;
        return;
    }
    if (flag2) {
        cout << 4;
        return;
    }
    cout << "MORTAL";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

//int8_t cnt[30];
//int8_t dp[1 << 29];
//vector<int> transitions;
//
//int8_t mex(vector<int8_t>& v) {
//    for (int i = 0; i < 30; i++) {
//        cnt[i] = 0;
//    }
//
//    for (int8_t i : v)
//        cnt[i] = 1;
//
//    for (int i = 0; i < 30; i++) {
//        if (!cnt[i])
//            return i;
//    }
//    return 30;
//}
//
//int8_t recurse(int mask) {
//    if (dp[mask] != -1)
//        return dp[mask];
//
//    vector<int8_t> v;
//    for (int i : transitions) {
//        if ((mask & i) != mask) {
//            v.push_back(recurse(mask & i));
//        }
//    }
//    return dp[mask] = mex(v);
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> visited;
    vector<int> piles;

    for (int i = 2; i * i <= n; i++) {
        if (!visited.count(i)) {
            ll pw = i;
            int c = 0;

            while (pw <= n) {
                visited.insert(pw);
                c++;
                pw *= i;
            }
            piles.push_back(c);
        }
    }

    int ans = (n - visited.size()) & 1;
    visited.clear();

    vector<int> g = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

    for (int i : piles)
        ans ^= g[i];

    cout << (ans ? "Vasya\n" : "Petya\n");

//    for (int i = 1; i <= 29; i++) {
//        int num = (1 << 29) - 1;
//        for (int j = i - 1; j < 29; j += i)
//            num ^= (1 << j);
//        transitions.push_back(num);
//    }
//
//    memset(dp, -1, sizeof(dp));
//    for (int i = 0; i <= 29; i++) {
//        cout << (int)recurse((1 << i) - 1) << ", ";
//    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

map<int, int> M;

int getSum(string &s) {
    int res = 0;
    for (char u : s) {
        if (u == '(') {
            res++;
        } else {
            res--;
        }
    }
    return res;
}

bool check(string &s, int sum) {
    int mn = 0;
    if (sum < 0) {
        mn = sum;
    }
    int res = 0;
    for (char u : s) {
        if (u == '(') {
            res++;
        } else {
            res--;
        }
        if (res < mn) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int sum = getSum(s);
        if (!check(s, sum)) {
            continue;
        }
        M[sum]++;
    }
    int res = 0;
    for (int i = 1; i < N; i++) {
        res += min(M[i], M[-i]);
    }
    int foo = M[0] / 2;
    res += foo;
    cout << res << endl;
    return 0;
}
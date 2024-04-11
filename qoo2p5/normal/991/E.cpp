#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = 20;

long long factorial[N];

long long _amount(const vector<int> &a) {
    int sum = 0;
    for (int x : a) {
        sum += x;
    }
    long long res = factorial[sum];
    for (int i = 0; i < 10; i++) {
        res /= factorial[a[i]];
    }
    return res;
}

long long amount(vector<int> a) {
    long long res = _amount(a);
    if (a[0] > 0) {
        a[0]--;
        res -= _amount(a);
    }
    return res;
}

long long solve(vector<int> a, int ptr = 0) {
    if (ptr == 10) {
        return amount(a);
    }

    if (a[ptr] == 0) {
        return solve(a, ptr + 1);
    }

    long long res = 0;
    for (int take = 1; take <= a[ptr]; take++) {
        vector<int> b = a;
        b[ptr] = take;
        res += solve(b, ptr + 1);
    }
    return res;
}

void run() {
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    string n;
    cin >> n;
    vector<int> cnt(10);
    for (char c : n) {
        cnt[(int) (c - '0')]++;
    }
    cout << solve(cnt) << "\n";
}
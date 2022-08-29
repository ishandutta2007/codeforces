#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int GOAL_MAX = 250005;

int find_equal_subsets(vector<int> &X) {
    sort(X.begin(), X.end());
    int n = int(X.size());
    int sum = accumulate(X.begin(), X.end(), 0);

    if (sum % 2 != 0)
        return -1;

    int goal = sum / 2;
    assert(goal < GOAL_MAX);
    vector<bitset<GOAL_MAX>> dp(n + 1);
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
        dp[i + 1] = dp[i] | dp[i] << X[i];

    if (!dp[n][goal])
        return -1;

    int current = goal;
    vector<bool> included(n, false);
    int size = 0;

    for (int i = n - 1; i >= 0; i--) {
        assert(dp[i + 1][current]);

        if (!dp[i][current]) {
            current -= X[i];
            assert(current >= 0 && dp[i][current]);
            included[i] = true;
            size++;
        }
    }

    assert(current == 0);
    vector<int> A, B;

    for (int i = 0; i < n; i++)
        if (included[i])
            A.push_back(X[i]);
        else
            B.push_back(X[i]);

    A.insert(A.end(), B.begin(), B.end());
    X = A;
    return size;
}

void run_case() {
    int N;
    cin >> N;
    vector<int> X(N);

    for (auto &x : X)
        cin >> x;

    int _;
    cin >> _;
    vector<int> Y(_);

    for (auto &y : Y)
        cin >> y;

    if (N != _) {
        cout << "No" << '\n';
        return;
    }

    int R = find_equal_subsets(X);
    int U = find_equal_subsets(Y);

    if (U < 0 || R < 0) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    bool swapped = false;

    if (U > R) {
        swapped = true;
        swap(U, R);
        swap(X, Y);
    }

    sort(Y.begin(), Y.begin() + U, greater<int>());
    sort(Y.begin() + U, Y.end(), greater<int>());
    sort(X.begin(), X.begin() + R);
    sort(X.begin() + R, X.end());
    vector<array<int, 2>> points;
    int x = 0, y = 0;

    for (int i = 0; i < N; i++) {
        y += i < U ? Y[i] : -Y[i];
        points.push_back({x, y});
        x += i < R ? X[i] : -X[i];
        points.push_back({x, y});
    }

    assert(x == 0 && y == 0);

    if (swapped) {
        for (auto &pt : points)
            swap(pt[0], pt[1]);
    }

    for (auto &pt : points)
        cout << pt[0] << ' ' << pt[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Computes the minimum number of +1/-1 changes to the array needed to make it non-decreasing.
// See https://codeforces.com/blog/entry/47094?#comment-315161 and https://codeforces.com/blog/entry/47821 for details.
template<typename T_out, typename T_in>
T_out slope_trick(const vector<T_in> &A) {
    priority_queue<T_in> pq;
    T_out ans = 0;

    for (const T_in &x : A) {
        pq.push(x);

        if (pq.top() > x) {
            ans += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= i;
    }

    cout << slope_trick<int64_t>(A) << '\n';
}
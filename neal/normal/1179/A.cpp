#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int N, Q;
deque<int> A;
vector<pair<int, int>> answers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    int big = *max_element(A.begin(), A.end());

    while (A.front() != big) {
        int a = A.front(); A.pop_front();
        int b = A.front(); A.pop_front();
        answers.emplace_back(a, b);
        A.push_front(max(a, b));
        A.push_back(min(a, b));
    }

    for (int q = 0; q < Q; q++) {
        long long m;
        cin >> m;
        m--;

        if (m < (int) answers.size()) {
            cout << answers[m].first << ' ' << answers[m].second << '\n';
            continue;
        }

        m -= answers.size();
        int index = 1 + m % (N - 1);
        cout << A.front() << ' ' << A[index] << '\n';
    }
}
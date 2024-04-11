#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, I;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> I;
    I *= 8;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    I /= N;
    int choices = I > 30 ? N + 1 : 1 << I;

    sort(A.begin(), A.end());
    map<int, int> freq;
    int distinct = 0;
    int best = N;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && (distinct < choices || freq.find(A[j]) != freq.end())) {
            if (freq[A[j]]++ == 0)
                distinct++;

            j++;
        }

        best = min(best, i + N - j);

        if (--freq[A[i]] == 0)
            distinct--;
    }

    cout << best << '\n';
}
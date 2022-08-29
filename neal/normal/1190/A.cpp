#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, M, K;
vector<long long> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    P.resize(M);

    for (long long &p : P) {
        cin >> p;
        p--;
    }

    long long answer = 0;

    for (int i = 0, j = 0; i < M; i = j) {
        long long position = P[i] - i;
        long long start = position - position % K;

        while (j < M && P[j] - i < start + K)
            j++;

        answer++;
    }

    cout << answer << '\n';
}
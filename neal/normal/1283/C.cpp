#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> F(N);
    vector<bool> exists(N, false);
    vector<int> positions;
    vector<int> missing;

    for (int i = 0; i < N; i++) {
        cin >> F[i];
        F[i]--;

        if (F[i] >= 0)
            exists[F[i]] = true;
        else
            positions.push_back(i);
    }

    for (int i = 0; i < N; i++)
        if (!exists[i])
            missing.push_back(i);

    int M = missing.size();
    assert((int) positions.size() == M);

    while (true) {
        shuffle(missing.begin(), missing.end(), rng);

        for (int i = 0; i < M; i++)
            F[positions[i]] = missing[i];

        bool good = true;

        for (int i = 0; i < N; i++)
            if (F[i] == i) {
                good = false;
                break;
            }

        if (good) {
            for (int i = 0; i < N; i++)
                cout << F[i] + 1 << (i < N - 1 ? ' ' : '\n');

            return 0;
        }
    }
}
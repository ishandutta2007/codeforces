#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N;
    cin >> N;
    vector<int> T(N);

    for (int &t : T)
        cin >> t;

    T.push_back(T[0]);
    bool one = true;

    for (int i = 0; i < N; i++)
        if (T[i] != T[i + 1]) {
            one = false;
            break;
        }

    if (one) {
        cout << 1 << '\n';

        for (int i = 0; i < N; i++)
            cout << 1 << (i < N - 1 ? ' ' : '\n');

        return;
    }

    bool two = N % 2 == 0;
    int equal = -1;

    if (N % 2 != 0) {
        for (int i = 0; i < N; i++)
            if (T[i] == T[i + 1]) {
                equal = i;
                break;
            }

        if (equal >= 0)
            two = true;
    }

    if (two) {
        equal = max(equal + 1, 0);
        vector<int> answer(N, 0);

        for (int i = 0; i < N; i++)
            answer[(equal + i) % N] = 1 + i % 2;

        cout << 2 << '\n';

        for (int i = 0; i < N; i++)
            cout << answer[i] << (i < N - 1 ? ' ' : '\n');

        return;
    }

    assert(N % 2 != 0);
    cout << 3 << '\n';

    for (int i = 0; i < N; i++) {
        int value = 1 + i % 2;

        if (i == N - 1)
            value = 3;

        cout << value << (i < N - 1 ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
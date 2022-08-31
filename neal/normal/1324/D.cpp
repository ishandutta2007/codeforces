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


int N;
vector<int> A, B, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);

    for (int &a : A)
        cin >> a;

    for (int &b : B)
        cin >> b;

    D.resize(N);

    for (int i = 0; i < N; i++)
        D[i] = A[i] - B[i];

    sort(D.begin(), D.end());
    long long total = 0;

    for (int i = N - 1, j = 0; i >= 0; i--) {
        while (j < i && D[i] + D[j] <= 0)
            j++;

        total += max(i - j, 0);
    }

    cout << total << '\n';
}
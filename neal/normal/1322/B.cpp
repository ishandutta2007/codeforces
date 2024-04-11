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


const int BITS = 25;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    int answer = 0;

    for (int bit = BITS - 1; bit >= 0; bit--) {
        int ones = 0, zeros = 0;

        for (int i = 0; i < N; i++)
            if (A[i] >> bit & 1)
                ones++;
            else
                zeros++;

        int count = (ones % 2) * (zeros % 2);
        vector<int> remainder(N);

        for (int i = 0; i < N; i++)
            remainder[i] = A[i] & ((1 << bit) - 1);

        sort(remainder.begin(), remainder.end());
        int carries = 0;

        for (int i = 0, j = N; i < N; i++) {
            while (j - 1 > i && remainder[i] + remainder[j - 1] >= 1 << bit)
                j--;

            carries += N - max(j, i + 1);
            carries %= 2;
        }

        count += carries;
        answer |= (count % 2) << bit;
    }

    cout << answer << '\n';
}
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    vector<int> tries(M);

    for (int &t : tries)
        cin >> t;

    tries.push_back(N);
    sort(tries.begin(), tries.end());
    vector<long long> freq(26, 0);

    for (int i = 0; i < N; i++) {
        int count = tries.end() - upper_bound(tries.begin(), tries.end(), i);
        freq[S[i] - 'a'] += count;
    }

    for (int i = 0; i < 26; i++)
        cout << freq[i] << (i < 25 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
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
string S;
string best;

void run_case() {
    cin >> S;
    N = S.size();
    best = "";
    vector<vector<bool>> palindrome(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < N; i++) {
        int start = i;
        int end = start + 1;
        palindrome[start][end] = true;

        while (start > 0 && end < N) {
            start--; end++;

            if (S[start] != S[end - 1])
                break;

            dbg(start, end);
            palindrome[start][end] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        int start = i;
        int end = start;
        palindrome[start][end] = true;

        while (start > 0 && end < N) {
            start--; end++;

            if (S[start] != S[end - 1])
                break;

            dbg(start, end);
            palindrome[start][end] = true;
        }
    }

    for (int common = 0; 2 * common <= N; common++) {
        for (int len = 0; len <= N - 2 * common; len++) {
            int option = 2 * common + len;

            if (option > (int) best.size()) {
                if (palindrome[common][common + len]) {
                    best = S.substr(0, common + len) + S.substr(N - common);
                } else if (palindrome[N - common - len][N - common]) {
                    best = S.substr(0, common) + S.substr(N - common - len);
                }
            }
        }

        if (S[common] != S[N - 1 - common])
            break;
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
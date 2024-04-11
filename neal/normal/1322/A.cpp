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

void impossible() {
    cout << -1 << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;

    if (N % 2 != 0)
        impossible();

    int left = 0, right = 0;

    for (char c : S)
        if (c == '(')
            left++;
        else
            right++;

    if (left != N / 2)
        impossible();

    int index = 0, start = 0, sum = 0, total = 0;

    while (index < N) {
        if (sum == 0 && S[index] == ')')
            start = index;

        if (sum == -1 && S[index] == '(')
            total += index - start + 1;

        sum += S[index] == '(' ? +1 : -1;
        index++;
    }

    cout << total << '\n';
}
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    vector<int> left_count(N + 1, 0);
    vector<int> right_count(N + 1, 0);

    for (int i = 0; i < N; i++)
        left_count[i + 1] = left_count[i] + (S[i] == '(');

    for (int i = N - 1; i >= 0; i--)
        right_count[i] = right_count[i + 1] + (S[i] == ')');

    int equal = -1;

    for (int i = 0; i <= N; i++)
        if (left_count[i] == right_count[i]) {
            equal = i;
            break;
        }

    assert(equal >= 0);
    vector<int> remove;

    for (int i = 0; i < N; i++)
        if (i < equal) {
            if (S[i] == '(')
                remove.push_back(i);
        } else {
            if (S[i] == ')')
                remove.push_back(i);
        }

    if (remove.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    cout << 1 << '\n';
    cout << remove.size() << '\n';

    for (int i = 0; i < (int) remove.size(); i++)
        cout << remove[i] + 1 << (i < (int) remove.size() - 1 ? ' ' : '\n');
}
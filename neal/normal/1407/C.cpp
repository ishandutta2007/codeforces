#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> indices(N);

    for (int i = 0; i < N; i++)
        indices[i] = i;

    auto &&query = [&](int a, int b) {
        cout << "? " << a + 1 << ' ' << b + 1 << endl;
        int result;
        cin >> result;
        return result;
    };

    vector<int> P(N, -1);

    while (indices.size() > 1) {
        int a = indices.back(); indices.pop_back();
        int b = indices.back(); indices.pop_back();
        int ab = query(a, b);
        int ba = query(b, a);

        if (ab > ba) {
            P[a] = ab;
            indices.push_back(b);
        } else {
            P[b] = ba;
            indices.push_back(a);
        }
    }

    P[indices.back()] = N;
    cout << '!';

    for (int x : P)
        cout << ' ' << x;

    cout << endl;
}
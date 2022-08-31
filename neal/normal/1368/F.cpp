#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int N, G, R;
vector<bool> on;
vector<bool> special;

void query(vector<int> lamps) {
    assert(int(lamps.size()) == G);
    cout << lamps.size() << '\n';
    output_vector(lamps, true);
    cout << flush;
    int x;
    cin >> x;
    x--;

    if (x < 0)
        exit(0);

    for (int lamp : lamps)
        on[lamp] = true;

    for (int i = 0; i < int(lamps.size()); i++)
        on[(x + i) % N] = false;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    G = R = -1;

    for (int g = 1; g <= N; g++) {
        int option = (N / g) * (g - 1) + max(N % g - 1, 0) - (g - 1);

        if (option > R) {
            R = option;
            G = g;
        }
    }

    assert(G > 0);
    on.assign(N, false);
    special.assign(N, false);

    for (int i = 0; i < N; i++)
        special[i] = i % G < G - 1 && i != N - 1;

    assert(accumulate(special.begin(), special.end(), 0) == R + (G - 1));

    while (accumulate(on.begin(), on.end(), 0) < R) {
        vector<int> lamps;

        for (int i = 0; i < N; i++)
            if (special[i] && !on[i]) {
                lamps.push_back(i);

                if (int(lamps.size()) >= G)
                    break;
            }

        query(lamps);
    }

    cout << 0 << endl;
}
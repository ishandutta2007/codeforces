#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 3e5 + 5;
const int BITS = 19;
const int INF = 1e9 + 5;

int N, Q;
vector<int> A;
int locations[BITS * (BITS - 1) / 2][N_MAX];
int L[BITS * (BITS - 1) / 2];
int dist[BITS];
bool visited[BITS];

inline int encode(int a, int b) {
    return b * (b - 1) / 2 + a;
}

bool solve(int x, int y) {
    // cerr << "solve " << x << ' ' << y << endl;

    for (int bit = 0; bit < BITS; bit++) {
        dist[bit] = INF;
        visited[bit] = false;

        if (A[x] >> bit & 1)
            dist[bit] = x;
    }

    while (true) {
        int best_bit = -1;

        for (int bit = 0; bit < BITS; bit++)
            if (!visited[bit] && (best_bit < 0 || dist[bit] < dist[best_bit]))
                best_bit = bit;

        if (best_bit < 0 || dist[best_bit] > y)
            return false;

        // cerr << best_bit << ": " << dist[best_bit] << endl;

        if (A[y] >> best_bit & 1)
            return true;

        visited[best_bit] = true;
        int index = dist[best_bit];

        for (int bit = 0; bit < BITS; bit++)
            if (!visited[bit] && dist[bit] > index) {
                int a = bit, b = best_bit;

                if (a > b)
                    swap(a, b);

                int e = encode(a, b);
                int position = lower_bound(locations[e], locations[e] + L[e], index) - locations[e];

                if (position == L[e])
                    continue;

                dist[bit] = min(dist[bit], locations[e][position]);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    memset(L, 0, sizeof(L));

    for (int i = 0; i < N; i++)
        for (int bit = 0; bit < BITS; bit++)
            if (A[i] >> bit & 1)
                for (int bit2 = bit + 1; bit2 < BITS; bit2++)
                    if (A[i] >> bit2 & 1) {
                        int e = encode(bit, bit2);
                        locations[e][L[e]++] = i;
                    }

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << (solve(x, y) ? "Shi" : "Fou") << '\n';
    }
}
// ./c-continuous-city.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
#define eb emplace_back
using edge = tuple<int, int, int>;

/*
 *
 * node 1 = start
 *
 * nodes 2..2+hbit = complete graph
 * 
 * node hbit+1 = end
 */

const int BITS = 20, START_NODE = 2, END_NODE = START_NODE + BITS + 1;
vector<edge> edges;
int L, R;

int nodeFor(int bit) { return START_NODE + (BITS-bit); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> R;
    // build complete graph first... :P
    for (int i = BITS; i >= 0; i--) {
        int node = START_NODE + (BITS-i);
        for (int j = START_NODE; j < node; j++)
            edges.eb(j, node, 1 << i);
        edges.eb(node, END_NODE, 1);
    }

    if (L == 1) {
        edges.eb(1, END_NODE, 1);
        L++;
    }
    int cur = L;
    for (int i = 19, p2 = 1 << i; i >= 0; i--, p2 >>= 1) {
        int cr = cur + p2 - 1;
        if (cr <= R) {
            edges.eb(1, nodeFor(i), cur-1);
            cur = cr+1;
        }
    }
    // printf("cur=%d\n", cur); fflush(stdout);
    assert(cur == R+1);

    cout << "YES\n";
    // sort(edges.begin(), edges.end());
    cout << END_NODE << ' ' << edges.size() << '\n';
    for (auto t : edges) {
        int x, y, z; tie(x, y, z) = t;
        cout << x << ' ' << y << ' ' << z << '\n';
    }

    return 0;
}
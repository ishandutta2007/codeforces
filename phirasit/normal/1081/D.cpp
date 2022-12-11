#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int size[N], group[N];
int n, m, k;

class edge {
public:
    int u, v, w;
} e[N];

int f(int x) {
    if (group[x] == x) return x;
    return group[x] = f(group[x]);
}
int main() {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        group[i] = i;
        size[i] = 0;
    }
    for (int i = 0; i < k; ++i) {
        int u; 
        cin >> u;
        size[u] = 1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e, e+m, [] (const edge &e1, const edge &e2) {
        return e1.w < e2.w;
    });

    for (int i = 0; i < m; ++i) {
        const int u = e[i].u, v = e[i].v;

        if (f(u) != f(v)) {
            size[f(u)] += size[f(v)];
            group[f(v)] = f(u);
        }

        if (size[f(u)] >= k) {
            for (int j = 0; j < k; ++j) {
                cout << e[i].w << " ";
            }
            cout << endl;
            break;
        }
    }

    return 0;
}
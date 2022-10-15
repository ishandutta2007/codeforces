#include <bits/stdc++.h>

using namespace std;

int const N = 20000;
int const INF = 1 << 30;

int q[N], d[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int head = 0;
    int tail = 0;
    q[tail++] = n;
    fill(d, d + N, INF);
    d[n] = 0;
    while (head < tail) {
        int v = q[head++];
        for (int i : {v - 1, 2 * v}) {
            if (i >= 0 && i < N && d[i] == INF) {
                d[i] = d[v] + 1;
                q[tail++] = i;
            }
        }
    }
    printf("%d\n", d[m]);
}
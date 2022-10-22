#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
struct Node{
    int id, v;
}e[V], s[V];

bool cmp(Node x, Node y) {
    return x.v < y.v;
}
int n, m, _, x;
int ans[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &x);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &e[i].v);
            e[i].id = i;
        }
        sort(e, e + n, cmp);
        for (int i = 0; i < m; ++i) s[i].v = 0, s[i].id = i;
        for (int i = n - 1; i >= 0; i -= m) {
            sort(s, s + m, cmp);
            for (int j = 0; j < min(i + 1, m); ++j) {
                ans[e[i - j].id] = s[j].id;
                s[j].v += e[i - j].v;
            }
        }
        puts("YES");
        for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1); puts("");
    }
    return 0;
}

/*
2
5 2 3
1 2 3 1 2
4 3 3
1 1 2 3
*/
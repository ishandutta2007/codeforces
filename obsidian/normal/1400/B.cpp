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

int _, A, B, c[2], w[2];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &A, &B);
        scanf("%d%d", &c[0], &c[1]);
        scanf("%d%d", &w[0], &w[1]);
        if (w[0] > w[1]) swap(c[0], c[1]), swap(w[0], w[1]);
        int ans = 0;
        for (int i = 0; i <= c[0]; ++i) {
            if (i * w[0] > A) break;
            int rea = A - i * w[0];
            int b = min(c[0] - i, B / w[0]);
            int reb = B - b * w[0];
            ans = max(ans, i + b +min(c[1], rea / w[1] + reb / w[1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
33 27
6 10
5 6
100 200
10 10
5 5
1 19
1 3
19 5
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define MAXN 200000

typedef pair<int, int> pii;
typedef long long LL;

int n, k;
map <int, LL> map1, map2;

int main() {
    scanf("%d %d", &n, &k);

    LL ans = 0;
    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        if (a % k == 0) {
            ans += map2[a / k];
            map2[a] += map1[a / k];
        }
        map1[a]++;
    }

    printf("%I64d\n", ans);

    return 0;
}
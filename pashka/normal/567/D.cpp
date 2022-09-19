#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;

map<int, int> segs;

int main()
{
    int n, k, a;
    scanf("%d %d %d", &n, &k, &a);

    segs[0] = n;
    int s = (n + 1) / (a + 1);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        x--;
        map<int, int>::iterator t = segs.upper_bound(x);
        t--;
        int l = t->second;
        s -= (l + 1) / (a + 1);
        int l1 = x - t->first;
        int l2 = l - l1 - 1;
        s += (l1 + 1) / (a + 1);
        s += (l2 + 1) / (a + 1);
//        printf("%d %d %d %d\n", l, l1, l2, s);
        segs[t->first] = l1;
        segs[x + 1] = l2;
        if (s < k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
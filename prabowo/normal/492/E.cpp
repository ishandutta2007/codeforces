#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair

typedef long long LL;

int n, m, dx, dy;
int apple[100002];

int main() {
    scanf("%d %d %d %d", &n, &m, &dx, &dy);

    if (n == 1) {
        printf("0 0\n");
        return 0;
    }

    LL invY = 1;
    while (invY * dy % n != 1) invY++;

    int x, y;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        LL step = (invY * y) % n;
        apple[i] = (x - step * dx) % n;
        if (apple[i] < 0) apple[i] += n;
    }

    sort(apple, apple+m);

    int maks = 0;
    int ans = 0;
    for (int i=0; i<m;) {
        int tmp = upper_bound(apple, apple+m, apple[i]) - apple;
        if (maks < tmp - i) {
            maks = tmp - i;
            ans = apple[i];
        }
        i = tmp;
    }

    printf("%d 0\n", ans);

    return 0;
}
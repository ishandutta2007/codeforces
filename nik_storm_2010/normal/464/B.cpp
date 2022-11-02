#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const double e = 1e-9;

int a[8][3], cnt[4], all;
double dist[4];
bool have;

ll sqr(int x)
{
    return 1LL * x * x;
}

void check()
{
    if (have) return;
    all = 0;
    for (int i = 0; i < 8; i++) for (int j = i + 1; j < 8; j++)
    {
        double o = sqrt(sqr(a[i][0] - a[j][0]) + sqr(a[i][1] - a[j][1]) + sqr(a[i][2] - a[j][2]));
        if (o == 0) return;
        bool ok = false;
        for (int k = 0; k < all; k++) if (abs(dist[k] - o) < e) ok = true, cnt[k]++;
        if (ok) continue;
        if (all == 3) return;
        dist[all] = o;
        cnt[all] = 1;
        all++;
    }
    if (all != 3) return;

    if (dist[0] > dist[1]) swap(dist[0], dist[1]), swap(cnt[0], cnt[1]);
    if (dist[0] > dist[2]) swap(dist[0], dist[2]), swap(cnt[0], cnt[2]);
    if (dist[1] > dist[2]) swap(dist[1], dist[2]), swap(cnt[1], cnt[2]);
    dist[2] /= dist[0];
    dist[1] /= dist[0];
    if (cnt[0] != 12) return;
    if (cnt[1] != 12) return;
    if (abs(dist[1] - sqrt(2) > e)) return;
    if (abs(dist[2] - sqrt(3) > e)) return;
    have = true;
    puts("YES");
    for (int i = 0; i < 8; i++) for (int j = 0; j < 3; j++)
    {
        printf("%d ", a[i][j]);
        if (j == 2) printf("\n");
    }
}

void rec(int x)
{
    if (x == 8)
    {
        check();
        return;
    }
    rec(x + 1);
    swap(a[x][0], a[x][1]);
    rec(x + 1);
    swap(a[x][1], a[x][2]);
    rec(x + 1);
    swap(a[x][0], a[x][1]);
    rec(x + 1);
    swap(a[x][1], a[x][2]);
    rec(x + 1);
    swap(a[x][0], a[x][1]);
    rec(x + 1);
    swap(a[x][1], a[x][2]);
}

int main()
{
    for (int i = 0; i < 8; i++) for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
    rec(0);
    if (!have) puts("NO");
    return 0;
}
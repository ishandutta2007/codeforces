#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5;

struct lemming
{
    int num, speed, weight;
    lemming(int num, int speed, int weight) : num(num), speed(speed), weight(weight) {}
    lemming() : num(0), speed(0), weight(0) {}
};

bool cmp(const lemming &a, const lemming &b)
{
    if (a.weight == b.weight) return (a.speed < b.speed);
    return (a.weight < b.weight);
}

lemming a[N];
int n, k, h;

bool check(double time)
{
    int have = 1;
    for (int i = 1; i <= n; i++)
    {
        if ((have * h) / (0.0 + a[i].speed) <= time) have++;
        if (have > k) return true;
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &n, &k, &h);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].weight);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].speed);
    for (int i = 1; i <= n; i++) a[i].num = i;
    sort(a + 1, a + n + 1, cmp);
    double left = 0, right = 2e9;
    for (int it = 1; it <= 100; it++)
    {
        double mid = (left + right) / 2;
        if (check(mid)) right = mid; else left = mid;
    }
    int have = 1;
    for (int i = 1; i <= n; i++)
    {
        if ((have * h) / (0.0 + a[i].speed) > right) continue;
        printf("%d ", a[i].num);
        have++;
        if (have > k) break;
    }
    return 0;
}
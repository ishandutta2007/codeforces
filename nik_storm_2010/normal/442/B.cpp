#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 200;

double prob[N];

double find(int l, int r)
{
    double res = 0;
    for (int i = l; i <= r; i++)
    {
        double add = prob[i];
        for (int j = l; j <= r; j++) if (i != j) add *= (1 - prob[j]);
        res += add;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &prob[i]);
    sort(prob + 1, prob + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) ans = max(ans, find(i, j));
    printf("%.9lf", ans);
    return 0;
}
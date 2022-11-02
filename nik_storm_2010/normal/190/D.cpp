#include<cstdio>
#include<map>

using namespace std;
const int N = 400000 + 10;

int a[N], cnt, n, k;
map <int, int> base;

void add(int x)
{
    base[x]++;
    if (base[x] == k) cnt++;
}

void del(int x)
{
    if (base[x] == k) cnt--;
    base[x]--;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int r = 1;
    long long ans = 0;
    for (int l = 1; l <= n; l++)
    {
        while (r <= n && cnt == 0) add(a[r]), r++;
        if (cnt != 0) ans += n - r + 2;
        del(a[l]);
    }
    printf("%I64d\n", ans);
    return 0;
}
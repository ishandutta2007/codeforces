#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1e17
#define N 100010

using namespace std;

int n, m;
long long a[N], b[N], kq = MAX;

long long Get(int x)
{
    long long res = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] < x) res += (1ll * x - a[i]);
    for(int i = 1; i <= m; i++)
        if(b[i] > x) res += (b[i] - 1ll * x);
    return res;
}

int main()
{
    //fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%I64d", a + i);
    for(int i = 1; i <= m; i++) scanf("%I64d", b + i);
    int l = 0, r = 1e9 + 1;
    while(r - l > 2)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        long long s1 = Get(m1);
        long long s2 = Get(m2);
        if(s1 > s2) l = m1;
        else r = m2;
    }
    for(int i = l; i <= r; i++) kq = min(kq, Get(i));
    printf("%I64d", kq);
    return 0;
}
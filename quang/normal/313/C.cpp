#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 2000010

using namespace std;

int n;
int a[N];
long long s[N], res;

int main()
{
    //fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    s[0] = 0;
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int k = 1; k <= n; k <<= 2)
        res += s[k];
    printf("%I64d", res);
    return 0;
}
#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 12345678912345ll
#define N 1010

using namespace std;

int n, m;
int v[N];
long long res;

int main()
{
    //fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", v + i);
    for(int i = 1; i <= m; i++) {
        int uu, vv;
        scanf("%d%d", &uu, &vv);
        res += min(v[uu], v[vv]);
    }
    printf("%I64d", res);
    return 0;
}
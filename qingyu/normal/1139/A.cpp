#include <bits/stdc++.h>

constexpr int N = 5e6 + 50;
int n;
char s[N];
long long ans;

int main() 
{
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; i++)
        if (!((s[i] - '0') & 1)) ans += i;
    printf("%lld", ans);
    return 0;
}
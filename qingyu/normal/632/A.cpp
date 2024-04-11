#include <bits/stdc++.h>
typedef long long ll;
ll p, ans, num;
int n;
std::string s[50];
int main()
{
    scanf("%d%lld", &n, &p);
    p >>= 1;
    for (int i = 1; i <= n; ++i) std::cin >> s[i];
    for (int i = n; i >= 1; --i)
    {
        num <<= 1;
        if(s[i] == "halfplus") ++num;
        ans += num;
    }
    printf("%lld", ans * p);
    return 0;
}
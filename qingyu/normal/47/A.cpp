#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);
    int S = 0;
    for (int i = 1; S < n; ++i) S += i;
    puts(S == n ? "YES" : "NO");
    return 0;	
}
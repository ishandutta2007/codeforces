#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

char s[100005];

int bucket[1000];

int main() {
    int n;
    scanf("%d%s", &n, s);
    if (n == 1) return printf("Yes"), 0;
    for (int i = 0; i < n; ++i)
        if(++bucket[s[i] - 'a'] >= 2)
            return printf("Yes"), 0;
    return printf("No"), 0;
}
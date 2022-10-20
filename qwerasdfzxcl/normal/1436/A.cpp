#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int n, m, ans=0;
        int a[200];
        scanf("%d %d", &n, &m);
        for (int j=0;j<n;j++) scanf("%d", &a[j]);
        for (int j=0;j<n;j++) ans += a[j];
        if (ans == m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
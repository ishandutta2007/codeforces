#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d %d\n", min(n, m), (n+m)/2-min(n, m));
    return 0;
}
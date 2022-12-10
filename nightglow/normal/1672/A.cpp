#include <bits/stdc++.h>
 
using namespace std;
 
int a[105];
 
void Main()
{
    int n;
    scanf("%d", &n); a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[n + 1] += a[i] - 1;
    if (a[n + 1] & 1) puts("errorgorn");
    else puts("maomao90");
}
 
int main()
{
    int T;
    scanf("%d", &T);
    for (;T--;) Main();
}
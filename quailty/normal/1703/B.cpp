#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    char s[55];
    scanf("%d%s",&n,s);
    sort(s,s+n);
    n+=unique(s,s+n)-s;
    return 0*printf("%d\n",n);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
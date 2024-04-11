#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    int len=to_string(n).size(),b=1;
    for(int i=1;i<len;i++)b*=10;
    return 0*printf("%d\n",n-b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
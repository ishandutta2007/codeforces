#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%*d%*d");
    for(int i=1;i<=n;i++)
        printf("%d",i&1);
    return 0;
}
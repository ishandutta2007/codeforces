#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int a[MAXN];
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        if(a[i]%a[1])return 0*printf("-1\n");
    printf("%d\n",2*m);
    for(int i=1;i<=m;i++)
        printf("%d %d%c",a[i],a[1]," \n"[i==m]);
    return 0;
}
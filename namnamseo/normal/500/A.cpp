#include <cstdio>

int data[30010];

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int i;
    for(i=1;i<n;++i) scanf("%d",data+i);
    for(i=1;i<t;i+=data[i]);
    if(i==t) puts("YES");
    else puts("NO");
    return 0;
}
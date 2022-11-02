#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch;
int que[110],head,b,a;
int main()
{
    scanf("%d",&a);
    ch=getchar();
    ch=getchar();
    while (ch!='e')
    {
        que[head++]=ch-'0';
        ch=getchar();
    }
    while ((head)&&(que[head-1]==0)) head--;
    scanf("%d",&b);
    if ((a==0)&&(b!=0))
    {
        for (int i=0;i<b;i++) printf("%d",que[i]);
        if (b<head)
        {
            printf(".");
            for (int i=b;i<head;i++) printf("%d",que[i]);
        }
    }
    else
    {
        printf("%d",a);
        for (int i=0;i<b;i++) printf("%d",que[i]);
        if (b<head)
        {
            printf(".");
            for (int i=b;i<head;i++) printf("%d",que[i]);
        }
    }
    return 0;
}
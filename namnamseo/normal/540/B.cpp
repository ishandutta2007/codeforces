#include <cstdio>

int n,k,p,x,y;

int data[1000];

int main()
{
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    int i;
    int less=0, sum=0;
    for(i=0;i<k;++i) {
        scanf("%d",data+i);
        sum+=data[i];
        if(data[i]<y) ++less;
    }
    int a=less, b=n/2;
    int needed=b-a;
    if(needed<0) needed=0;
    if(needed>n-k) needed=n-k;
    if(a > b || sum+needed+(n-k-needed)*y>x) {
        puts("-1");
        return 0;
    }
    for(i=0;i<needed;++i) printf("1 ");
    for(i=0;i<n-k-needed;++i) printf("%d ",y);
    return 0;
}
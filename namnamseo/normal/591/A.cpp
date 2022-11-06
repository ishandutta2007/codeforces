#include <cstdio>

int main()
{
    int l;
    int p,q;
    scanf("%d%d%d",&l,&p,&q);
    printf("%.9f\n",p*l*1.0/(p+q));
    return 0;
}
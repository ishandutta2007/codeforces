#include <cstdio>

int main()
{
    int n,data[120];
    int x[120];
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++) scanf("%d",data+i);
    x[0]=data[0];
    for(i=1;i<n;i++) x[i]=x[i-1]^data[i];
    int m=-1,t;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
            t=x[j];
            if(i) t^=x[i-1];
            if(m<t) m=t;
        }
    printf("%d\n",m);
    return 0;
}
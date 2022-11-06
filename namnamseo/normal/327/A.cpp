#include <cstdio>

int main()
{
    int data[110];
    int i,n,b;
    scanf("%d",&n);
    scanf("%d",data);
    for(i=1;i<n;i++){
        scanf("%d",&b);
        data[i]=data[i-1]+b;
    }
    int j;
    int rs;
    int ans = -200;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            rs = data[j];
            if(i) rs -= data[i-1];
            rs = j-i+1-2*rs;
            if(ans<rs) ans=rs;
        }
    }
    printf("%d\n",ans+data[n-1]);
    return 0;
}
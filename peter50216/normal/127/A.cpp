#include<stdio.h>
#include<math.h>
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    double ans=0;
    int x1,y1,x,y;
    scanf("%d%d",&x1,&y1);
    for(i=1;i<n;i++){
    scanf("%d%d",&x,&y);
    ans+=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    x1=x;y1=y;
    }
    printf("%.9lf\n",ans/50*k);
}
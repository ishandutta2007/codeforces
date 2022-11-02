#include<stdio.h>
int in[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)scanf("%d",in+i);
    int a=0;
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i=x;i<y;i++)a+=in[i];
    printf("%d\n",a);
}
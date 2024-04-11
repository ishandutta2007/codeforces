#include<stdio.h>
int a[1000];
int main(){
    int n,i;
    scanf("%d",&n);
    int cc=0;
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]%2==0)cc++;
    }
    for(i=0;i<n;i++){
    if(cc==1&&a[i]%2==0)printf("%d\n",i+1);
    else if(cc==n-1&&a[i]%2!=0)printf("%d\n",i+1);
    }
}
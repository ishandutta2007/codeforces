#include <stdio.h>
int a[100001];
int main(){
int n;scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",a+i);for(int i=0;i<n;i++)printf("%d ",a[i]+a[i+1]);
}
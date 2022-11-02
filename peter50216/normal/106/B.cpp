#include<stdio.h>
int a[1000],b[1000],c[1000],d[1000];
int main(){
    int n,i,mi=1000000000,p,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(i=0;i<n;i++){
    for(j=0;j<n;j++)if(a[j]>a[i]&&b[j]>b[i]&&c[j]>c[i])break;
    if(j==n){
        if(d[i]<mi){
        mi=d[i];
        p=i;
        }
    }
    }
    printf("%d\n",p+1);
}
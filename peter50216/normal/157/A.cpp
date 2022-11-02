#include<stdio.h>
int a[100][100],s[100],t[100];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            s[i]+=a[i][j];
            t[j]+=a[i][j];
        }
    }
    int aa=0;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(t[j]>s[i])aa++;
    printf("%d\n",aa);
}
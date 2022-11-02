#include<stdio.h>
int in[1010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    int ma=0;
    for(i=0;i<n;i++){
    int l=i,r=i;
    for(;l>0&&in[l-1]<=in[l];l--);
    for(;r<n-1&&in[r+1]<=in[r];r++);
    if(ma<r-l+1)ma=r-l+1;
    }
    printf("%d\n",ma);
}
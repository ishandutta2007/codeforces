#include<stdio.h>
int in[110];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    int ma=-1,mp1,mp2;
    for(i=0;i<n;i++)if(in[i]>ma){
        ma=in[i];mp1=i;
    }
    ma=10000;
    for(i=n-1;i>=0;i--)if(in[i]<ma){
        ma=in[i];mp2=i;
    }
    printf("%d\n",mp1+n-1-mp2+(mp1>mp2?-1:0));
}
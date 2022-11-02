#include<stdio.h>
int n;
int in[30000];
int ma=-2000000000;
inline void tries(int st){
    if(n/st<=2)return;
    int i,j;
    for(i=0;i<st;i++){
        int s=0;
        for(j=i;j<n;j+=st){
            s+=in[j];
        }
        if(s>ma)ma=s;
    }
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            tries(i);
            tries(n/i);
        }
    }
    printf("%d\n",ma);
}
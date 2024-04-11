#include<stdio.h>
int main(){
    int t=0;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        long long int j=1;
        while(k>(j*(j+1))/2){
            j++;
        }
        long long int c=k-((j*(j-1))/2);
        if((n-1-j)>0){
            for(int k=1;k<=n-1-j;k++){
                printf("a");
            }
        }
        printf("b");
        for(int m=1;m<=j-c;m++){
            printf("a");
        }
        printf("b");
        for(int p=1;p<=c-1;p++){
            printf("a");
        }
        printf("\n");
    }
}
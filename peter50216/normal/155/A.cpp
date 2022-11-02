#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int mi=-100000,ma=100000;
    int c=-2;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a<ma){
            ma=a;
            c++;
        }
        if(a>mi){
            mi=a;
            c++;
        }
    }
    printf("%d\n",c);
}
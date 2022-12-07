#include<stdio.h>
int main(){
    int t=0;
    scanf("%d",&t);
    int counter=1;
    t=9*t;
    char s[10];
    while(t--){
        scanf(" %s ",&s);
        for(int i=0;i<9;i++)
        {
            if(s[i]=='1')
                s[i] = '2';
        }
        printf("%s\n",s);
    }
    return 0;
}
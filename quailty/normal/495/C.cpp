#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
char s[100005];
int main()
{
    scanf("%s",s);
    int len=strlen(s),tot=0,sum=0,last=0,flag=1;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            sum++;
        }
        if(s[i]==')'){
            sum--;
        }
        if(s[i]=='#'){
            tot++;
            last=i;
            sum--;
        }
        if(sum<0){
            flag=0;
            break;
        }
    }
    sum++;
    int resum=0,reflag=1;
    for(int i=last+1;i<len;i++){
        if(reflag){
            if(s[i]=='('){
                reflag=0;
                resum++;
            }
        }
        else{
            if(s[i]=='('){
                resum++;
            }
            if(s[i]==')'){
                if(resum>0)resum--;
            }
        }
    }
    if(flag&&resum==0){
        for(int i=0;i<=tot-2;i++){
                printf("1\n");
            }
        printf("%d\n",sum);
    }
    else printf("-1\n");
    return 0;
}
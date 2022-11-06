#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
char num[100005];
int main()
{
    scanf("%s",num);
    int n=strlen(num);
    bool impos=1;
    for(int i=0;i<n;i++){
        if((num[i]-'0')%2==0){
            impos=0;
            break;
        }
    }
    if(impos)printf("-1");
    else{
        int last=0;
        bool isch=0;
        for(int i=0;i<n;i++){
            if((num[i]-'0')%2==0){
                last=i;
                if(num[i]<num[n-1]){
                    isch=1;
                    char t=num[i];
                    num[i]=num[n-1];
                    num[n-1]=t;
                    break;
                }
            }
        }
        if(!isch){
            char t=num[last];
            num[last]=num[n-1];
            num[n-1]=t;
        }
        printf("%s",num);
    }
    return 0;
}
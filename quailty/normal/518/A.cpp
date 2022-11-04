#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[105],t[105];
    scanf("%s%s",s,t);
    int n=strlen(s);
    bool isok=0,hok=0;
    int flag;
    for(int i=0;i<n;i++)
    {
        if(!hok)
        {
            if(s[i]<=t[i]-2)
            {
                s[i]=s[i]+1;
                isok=1;
                break;
            }
            else if(s[i]==t[i]-1)
            {
                if(!hok)
                {
                    flag=i;
                    hok=1;
                }
            }
        }
        else
        {
            if(s[i]<'z')
            {
                s[i]='z';
                isok=1;
                break;
            }
            else if(t[i]>'a')
            {
                s[flag]=t[flag];
                s[i]='a';
                isok=1;
                break;
            }
            else
            {
                s[i]='a';
            }
        }
    }
    if(isok)printf("%s",s);
    else printf("No such string");
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[205],t[205];
int main()
{
    scanf("%s",s);
    int loc[2]={0,0};
    for(int i=0;s[i];i++)
    {
        if(s[i]=='.')loc[0]=i;
        if(s[i]=='e')loc[1]=i;
    }
    int b=0;
    for(int i=loc[1]+1;s[i];i++)
        b=b*10+s[i]-'0';
    for(int i=0;i<loc[1];i++)
        t[i]=s[i];
    for(int i=loc[0];t[i+1] && b;i++)
        swap(t[i],t[i+1]),b--;
    if(b)
    {
        for(int i=0;i+1<loc[1];i++)
            printf("%c",t[i]);
        while(b--)printf("0");
    }
    else
    {
        while(1)
        {
            if(t[loc[1]-1]!='0' && t[loc[1]-1]!='.')break;
            loc[1]--;
            if(t[loc[1]]=='.')break;
        }
        for(int i=0;i<loc[1];i++)
            printf("%c",t[i]);
    }
    return 0;
}
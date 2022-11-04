#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[105];
    scanf("%s",s);
    int cntl=0,cntu=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z')cntl++;
        else cntu++;
    }
    if(cntl>=cntu)
    {
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                s[i]=s[i]-'a'+'A';
            }
        }
    }

    printf("%s",s);
    return 0;
}
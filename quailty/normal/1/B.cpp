#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool judge(char str[],int len)
{
    if(str[0]!='R')return 0;
    if(str[1]<'0'||str[1]>'9')return 0;
    int loc=2;
    while(loc<len && str[loc]!='C')loc++;
    if(loc==len)return 0;
    return 1;
}
void print(int c)
{
    if(c>=0)
    {
        print(c/26-1);
        printf("%c",c%26+'A');
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s[15];
        scanf("%s",s);
        int len=strlen(s);
        if(judge(s,len))
        {
            int loc=1;
            int c=0,r=0;
            for(;loc<len && s[loc]!='C';loc++)
            {
                r=r*10+s[loc]-'0';
            }
            loc++;
            for(;loc<len;loc++)
            {
                c=c*10+s[loc]-'0';
            }
            int tot=0;
            print(c-1);
            printf("%d\n",r);
        }
        else
        {
            int c=0,r=0;
            int loc=0;
            for(;loc<len && s[loc]>='A' && s[loc]<='Z';loc++)
            {
                c=c*26+s[loc]-'A'+1;
            }
            for(;loc<len && s[loc]>='0' && s[loc]<='9';loc++)
            {
                r=r*10+s[loc]-'0';
            }
            printf("R%dC%d\n",r,c);
        }
    }
    return 0;
}
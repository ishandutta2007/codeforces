#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
bool isValid(char x)
{
    if(x>='a' && x<='z')return 1;
    if(x>='A' && x<='Z')return 1;
    if(x>='0' && x<='9')return 1;
    return x=='_';
}
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    bool host=0,resc=0,isok=1;
    for(int i=0;i<n;i++)
        if(!isValid(s[i]))
        {
            if(i==0)isok=0;
            else if(s[i]=='@')
            {
                if(!host && (i<n-1 && isValid(s[i+1])))host=1;
                else isok=0;
            }
            else if(s[i]=='.')
            {
                if(resc)isok=0;
                if(!host || i==n-1 || !isValid(s[i+1]))isok=0;
            }
            else if(s[i]=='/')
            {
                if(resc)isok=0;
                if(host && (i<n-1 && isValid(s[i+1])))resc=1;
                else isok=0;
            }
            else isok=0;
        }
    if(!host)isok=0;
    printf("%s",(isok ? "YES" : "NO"));
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char str[100005],res[100005];
bool isAlpha(char x)
{
    return x>='a' && x<='z';
}
int main()
{
    gets(str);
    for(int i=0,j=0,k=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            if(k)res[j++]=' ',k=0;
        }
        else if(isAlpha(str[i]))
        {
            res[j++]=str[i];
            k=1;
        }
        else
        {
            if(res[j-1]==' ')res[j-1]=str[i];
            else res[j++]=str[i];
            res[j++]=' ';
            k=0;
        }
    }
    puts(res);
    return 0;
}
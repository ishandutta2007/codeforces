#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int cal(int n)
{
    int res=0;
    for(int i=0;i+1<n;i++)
        res+=(s[i]=='V' && s[i+1]=='K');
    return res;
}
int main()
{
    scanf("%s",s);
    int n=strlen(s),res=cal(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='V')s[i]='K';
        else s[i]='V';
        res=max(res,cal(n));
        if(s[i]=='V')s[i]='K';
        else s[i]='V';
    }
    return 0*printf("%d\n",res);
}
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int MAXM=35;
char s[MAXN],t[MAXM];
int main()
{
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    int res=0;
    for(int i=0;i+m<=n;i++)
    {
        bool flag=1;
        for(int j=0;j<m;j++)
            if(s[i+j]!=t[j])flag=0;
        if(flag)
        {
            s[i+m-1]='#';
            res++;
        }
    }
    printf("%d\n",res);
    return 0;
}
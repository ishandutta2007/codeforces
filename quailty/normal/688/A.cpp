#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    int n,d,res=0,now=0;
    scanf("%d%d",&n,&d);
    while(d--)
    {
        scanf("%s",s);
        int lose=1;
        for(int i=0;i<n;i++)
            lose&=s[i]-'0';
        if(lose)now=0;
        else now++;
        res=max(res,now);
    }
    return 0*printf("%d",res);
}
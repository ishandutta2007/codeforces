#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][105];
int main()
{
    int R,C,res=0;
    scanf("%d%d",&R,&C);
    for(int i=1;i<=R;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=C;i++)
        if(s[R][i]=='B' && s[R][i]!=s[R][i-1])res++;
    printf("%d\n",res);
    return 0;
}
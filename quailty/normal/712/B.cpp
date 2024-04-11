#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int main()
{
    scanf("%s",s);
    int x=0,y=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='L')y--;
        if(s[i]=='R')y++;
        if(s[i]=='U')x--;
        if(s[i]=='D')x++;
    }
    if((x+y)&1)printf("-1");
    else printf("%d",(abs(x)+abs(y))/2);
    return 0;
}
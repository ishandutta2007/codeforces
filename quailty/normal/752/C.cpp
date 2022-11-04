#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[200005];
int main()
{
    int n;
    scanf("%d%s",&n,s);
    int lx=0,ly=0,res=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='U')
        {
            if(lx<0)res++,ly=0;
            lx=1;
        }
        if(s[i]=='D')
        {
            if(lx>0)res++,ly=0;
            lx=-1;
        }
        if(s[i]=='L')
        {
            if(ly<0)res++,lx=0;
            ly=1;
        }
        if(s[i]=='R')
        {
            if(ly>0)res++,lx=0;
            ly=-1;
        }
    }
    return 0*printf("%d",res+1);
}
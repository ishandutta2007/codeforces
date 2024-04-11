#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[205];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            int x=0,y=0;
            for(int k=i;k<=j;k++)
            {
                if(s[k]=='U')y++;
                if(s[k]=='R')x++;
                if(s[k]=='D')y--;
                if(s[k]=='L')x--;
            }
            if(x==0 && y==0)cnt++;
        }
    printf("%d\n",cnt);
    return 0;
}
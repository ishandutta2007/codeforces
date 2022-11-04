#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105],res[105][255];
int main()
{
    int n,d=0,w=0,h=0;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='[')
        {
            res[d][w]='+';
            res[d][w+1]='-';
            d++,w++;
        }
        else
        {
            d--;
            if(s[i-1]=='[')w+=3;
            res[d][w]='+';
            res[d][w-1]='-';
            w++;
        }
        h=max(h,d);
    }
    for(int i=h+1;i<=2*h;i++)
        for(int j=0;j<w;j++)
            res[i][j]=res[2*h-i][j];
    for(int j=0;j<w;j++)
        for(int i=0,k=0;i<=2*h;i++)
        {
            if(res[i][j]=='+')k^=1;
            else if(!res[i][j])res[i][j]=" |"[k];
        }
    for(int i=0;i<=2*h;i++)
        printf("%s\n",res[i]);
    return 0;
}
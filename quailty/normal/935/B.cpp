#include<bits/stdc++.h>
using namespace std;
char str[100005];
int main()
{
    int n,x=0,y=0,res=0;
    scanf("%d%s",&n,str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='U')x++;
        if(str[i]=='R')y++;
        res+=(x==y && str[i+1]==str[i]);
    }
    return 0*printf("%d\n",res);
}
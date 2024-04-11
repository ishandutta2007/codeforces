#include<bits/stdc++.h>
using namespace std;
char str[1005];
int main()
{
    int n;
    scanf("%d%s",&n,str);
    for(int i=0;i+1<n;i++)
        if(str[i]=='1' && str[i+1]=='1')
            return 0*printf("No\n");
    for(int i=0;i<n;i++)if(str[i]=='0')
    {
        str[i]='1';
        bool isok=1;
        for(int i=0;i+1<n;i++)
            isok&=!(str[i]=='1' && str[i+1]=='1');
        if(isok)return 0*printf("No\n");
        str[i]=0;
    }
    return 0*printf("Yes\n");
}
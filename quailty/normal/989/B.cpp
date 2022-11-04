#include<bits/stdc++.h>
using namespace std;
char str[2005];
int main()
{
    int n,p;
    scanf("%d%d%s",&n,&p,str+1);
    bool isok=0;
    for(int i=1;i<=n-p;i++)
    {
        if(str[i]=='.')
        {
            isok=1;
            if(str[i+p]=='.')str[i]='0',str[i+p]='1';
            else str[i]='0'+'1'-str[i+p];
        }
        else
        {
            if(str[i+p]=='.')
            {
                isok=1;
                str[i+p]='0'+'1'-str[i];
            }
            else isok|=(str[i]!=str[i+p]);
        }
    }
    for(int i=1;i<=n;i++)
        if(str[i]=='.')str[i]='0';
    printf("%s\n",(isok ? str+1 : "No"));
    return 0;
}
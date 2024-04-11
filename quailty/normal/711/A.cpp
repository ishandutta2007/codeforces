#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005][7];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    bool isok=0;
    for(int i=0;i<n && !isok;i++)
    {
        if(s[i][0]=='O' && s[i][1]=='O')
        {
            s[i][0]=s[i][1]='+';
            isok=1;
            break;
        }
        if(s[i][3]=='O' && s[i][4]=='O')
        {
            s[i][3]=s[i][4]='+';
            isok=1;
            break;
        }
    }
    if(!isok)printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%s\n",s[i]);
    }
    return 0;
}
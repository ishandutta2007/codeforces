#include<bits/stdc++.h>
using namespace std;
char str[4][105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<4;i++)
        for(int j=0;j<n;j++)
            str[i][j]='.';
    if(k%2==0)
    {
        for(int i=1;i<=k/2;i++)
            str[1][i]=str[2][i]='#';
        printf("YES\n");
        for(int i=0;i<4;i++)
            printf("%s\n",str[i]);
    }
    else if(k>3)
    {
        for(int i=1;i<=(k+1)/2;i++)
            str[1][i]=str[2][i]='#';
        str[1][2]='.';
        printf("YES\n");
        for(int i=0;i<4;i++)
            printf("%s\n",str[i]);
    }
    else if(k==1)
    {
        str[1][n/2]='#';
        printf("YES\n");
        for(int i=0;i<4;i++)
            printf("%s\n",str[i]);
    }
    else if(k==3)
    {
        str[1][n/2-1]=str[1][n/2]=str[1][n/2+1]='#';
        printf("YES\n");
        for(int i=0;i<4;i++)
            printf("%s\n",str[i]);
    }
    else printf("NO\n");
    return 0;
}
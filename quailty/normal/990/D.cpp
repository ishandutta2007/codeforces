#include<bits/stdc++.h>
using namespace std;
char str[1005][1005];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    bool flag=0;
    if(a>b)swap(a,b),flag=1;
    if(a>1)return 0*printf("NO\n");
    if((n==2 || n==3) && b==1)return 0*printf("NO\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            str[i][j]='0';
    for(int i=0;i<n-b;i++)
        str[i][i+1]=str[i+1][i]='1';
    if(!flag)for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j)str[i][j]='0'+'1'-str[i][j];
    printf("YES\n");
    for(int i=0;i<n;i++)
        printf("%s\n",str[i]);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int now=0;
        for(int j=0;j<n;j++)
            if(s[i][j]=='C')now++;
        res+=now*(now-1)/2;
    }
    for(int i=0;i<n;i++)
    {
        int now=0;
        for(int j=0;j<n;j++)
            if(s[j][i]=='C')now++;
        res+=now*(now-1)/2;
    }
    printf("%d",res);
    return 0;
}
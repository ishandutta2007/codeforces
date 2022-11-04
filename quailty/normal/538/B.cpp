#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char n[10];
int ans[15];
int main()
{
    scanf("%s",n);
    int t=strlen(n);
    int cnt=0;
    for(int i=0;i<t;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cnt=max(cnt,n[i]-'0');
            ans[j]=ans[j]*10;
            if(j<=n[i]-'0')
            {
                ans[j]++;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
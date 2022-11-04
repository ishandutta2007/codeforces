#include<bits/stdc++.h>
using namespace std;
char str[105][105];
int cnt[105][105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j+k<=n;j++)
        {
            bool isok=1;
            for(int t=j;t<j+k;t++)
                isok&=(str[i][t]=='.');
            if(isok)for(int t=j;t<j+k;t++)
                cnt[i][t]++;
        }
    for(int i=0;i+k<=n;i++)
        for(int j=0;j<n;j++)
        {
            bool isok=1;
            for(int t=i;t<i+k;t++)
                isok&=(str[t][j]=='.');
            if(isok)for(int t=i;t<i+k;t++)
                cnt[t][j]++;
        }
    int res[2]={0,0},mx=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(cnt[i][j]>mx)
            {
                mx=cnt[i][j];
                res[0]=i,res[1]=j;
            }
    printf("%d %d\n",res[0]+1,res[1]+1);
    return 0;
}
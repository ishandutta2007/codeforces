#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[2][366];
int main()
{
    int n;
    scanf("%d",&n);
    char s[5];
    int l,r;
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",s,&l,&r);
        int t=0;
        if(*s=='F')t=1;
        for(int j=l;j<=r;j++)
            cnt[t][j-1]++;
    }
    int res=0;
    for(int i=0;i<366;i++)
        res=max(res,2*min(cnt[0][i],cnt[1][i]));
    printf("%d",res);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[5];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int in;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        cnt[in%2]++;
    }
    bool flag;
    if(n==k)
    {
        if(cnt[1]%2==1)flag=0;
        else flag=1;
    }
    else if((n-k)%2==1)
    {
        if(cnt[1]<=(n-k)/2)flag=1;
        else if(k%2==0 && cnt[0]<=(n-k)/2)flag=1;
        else flag=0;
    }
    else
    {
        if(k%2==1 && cnt[0]<=(n-k)/2)flag=0;
        else flag=1;
    }
    if(!flag)printf("Stannis\n");
    else printf("Daenerys\n");
    return 0;
}
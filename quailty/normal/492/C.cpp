#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
pair<int,int> c[100005];
int main()
{
    int n,r,avg;
    scanf("%d%d%d",&n,&r,&avg);
    ll now=1LL*n*avg,res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i].second,&c[i].first);
        now-=c[i].second;
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++)
    {
        if(now>r-c[i].second)
        {
            now-=r-c[i].second;
            res+=1LL*c[i].first*(r-c[i].second);
        }
        else if(now>0)
        {
            res+=now*c[i].first;
            now=0;
        }
    }
    return 0*printf("%I64d",res);
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int c[300005],tim[300005];
priority_queue<pair<int,int> > pq;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll res=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]),res-=1LL*c[i]*i;
    for(int i=k+1,j=1;i<=k+n;i++)
    {
        while(j<=n && j<=i)
        {
            pq.push(make_pair(c[j],j));
            j++;
        }
        pair<int,int> tmp=pq.top();
        tim[tmp.second]=i;
        res+=1LL*tmp.first*i;
        pq.pop();
    }
    printf("%lld\n",res);
    for(int i=1;i<=n;i++)
        printf("%d ",tim[i]);
    return 0;
}
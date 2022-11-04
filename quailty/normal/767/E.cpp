#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int c[MAXN],w[MAXN],res[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    priority_queue<pair<int,int> >pq;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        m-=c[i]%100;
        if(c[i]%100)pq.push(make_pair(-w[i]*(100-c[i]%100),i));
        if(m<0)
        {
            pair<int,int> tmp=pq.top();
            pq.pop();
            sum-=tmp.first;
            res[tmp.second]=1;
            m+=100;
        }
    }
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++)
    {
        if(res[i])printf("%d %d\n",c[i]/100+1,0);
        else printf("%d %d\n",c[i]/100,c[i]%100);
    }
    return 0;
}
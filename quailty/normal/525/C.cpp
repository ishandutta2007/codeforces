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
const int MAXL=1000005;
int cnt[MAXL];
queue<int>q;
int main()
{
    int n;
    scanf("%d",&n);
    int l;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l);
        cnt[l]++;
    }
    for(int i=MAXL;i>=2;i--)
    {
        if(cnt[i]&1)
        {
            cnt[i]--;
            if(cnt[i-1])cnt[i-1]++;
        }
    }
    for(int i=MAXL;i>=2;i--)
    {
        while(cnt[i]>0)
        {
            q.push(i);
            cnt[i]-=2;
        }
    }
    ll ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(!q.empty())
        {
            int v=q.front();
            q.pop();
            ans+=1LL*u*v;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
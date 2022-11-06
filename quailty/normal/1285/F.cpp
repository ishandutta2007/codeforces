#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int c[MAXN],mu[MAXN],cnt[MAXN];
vector<int> f[MAXN];
void add(int x,int v)
{
    for(auto &d:f[x])
        cnt[d]+=v;
}
int check(int x)
{
    int res=0;
    for(auto &d:f[x])
        res+=mu[d]*cnt[d];
    return res;
}
int main()
{
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            f[j].push_back(i);
    for(int i=(mu[1]=1);i<MAXN;i++)
        for(int j=2*i;j<MAXN;j+=i)
            mu[j]-=mu[i];
    int n;
    scanf("%d",&n);
    ll res=0;
    for(int i=1,a;i<=n;i++)
        scanf("%d",&a),c[a]=1,res=max(res,1LL*a);
    for(int d=1;d<MAXN;d++)
    {
        for(int i=1;i<=(MAXN-1)/d;i++)
            cnt[i]=0;
        stack<int> stk;
        for(int i=(MAXN-1)/d;i>0;i--)if(c[i*d])
        {
            while(!stk.empty() && check(i))
            {
                int u=stk.top();
                res=max(res,1LL*i*u*d);
                add(u,-1),stk.pop();
            }
            add(i,1),stk.push(i);
        }
    }
    printf("%lld\n",res);
    return 0;
}
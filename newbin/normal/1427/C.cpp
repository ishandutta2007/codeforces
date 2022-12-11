#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define lson rt<<1
#define rson rt<<1|1
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn=1e5+5;
int val[maxn<<2];
void push_up(int rt)
{
    val[rt]=max(val[lson],val[rson]);
}
void update(int l,int r,int rt,int x,int v)
{
    if(l==r) {val[rt]=v;return;}
    int m=l+r>>1;
    if(x<=m) update(l,m,lson,x,v);
    else update(m+1,r,rson,x,v);
    push_up(rt);
}
int query(int l,int r,int rt,int L,int R)
{
    if(L<=l&&R>=r) return val[rt];
    int m=l+r>>1,res=0;
    if(L<=m) res=max(res,query(l,m,lson,L,R));
    if(m<R) res=max(res,query(m+1,r,rson,L,R));
    return res;
}
int l,n;
int t[maxn],x[maxn],y[maxn];
int dp[maxn];
int dis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main()
{
	scanf("%d%d",&l,&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",t+i,x+i,y+i);
	x[0]=1,y[0]=1;
	for(int i=1;i<=n;++i)
    {
        if(dis(i,0)<=t[i]) dp[i]=1;
        else dp[i]=-1e9;
        for(int j=i-1;j>=max(1,i-1000);j--)
        {
            if(dis(i,j)<=t[i]-t[j]) dp[i]=max(dp[j]+1,dp[i]);
        }
        if(i-1000>=1) dp[i]=max(dp[i],query(1,n,1,1,i-1000)+1);
        update(1,n,1,i,dp[i]);
    }
    //for(int i=1;i<=n;++i) printf("%d ",dp[i]);
    int ans=max(0,val[1]);
    printf("%d\n",ans);
	return 0;
}
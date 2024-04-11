#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
typedef long long ll;
const int N = 3e5+1;

ll U[N],V[N],u1[N],v1[N],BBA[N],cost[N*2],w[N*2],F[N*2];
bool incir[N];
int n,cnt,head[N],ne[N*2],to[N*2],pp[N],tot,sss[N],top,pre[N];
void build(int x,int y,int v)
{
	ne[++cnt]=head[x];
		w[cnt]=v;
		head[x]=cnt;
		to[cnt]=y;
}
ll ans,sum,Mx;
int DP(int x)
{
	pp[x]=++tot;
	for(int i=head[x],y;i;i=ne[i])
	if((y=to[i])!=pre[x])
	{
		if(!pp[y])
		{
			pre[y]=x;
			cost[y]=w[i];
			DP(y);
		}
		else if(pp[y]>pp[x])
		{
			 while(x!=y)
			 {
				sss[++top]=y;
				BBA[top]=cost[y];
				incir[y]=1;
				y=pre[y];
			 }
			 sss[++top]=x;
			 BBA[top]=w[i];
			 incir[x]=1;
			 return 0;
		}
	}
}

void calc(int x,int fa)
{
	for(int i=head[x];i;i=ne[i])
		if(to[i]!=fa&&!incir[to[i]])
		{
			calc(to[i],x);
			ans=max(ans,F[x]+F[to[i]]+w[i]);
			F[x]=max(F[x],F[to[i]]+w[i]);
		}
}

int main()
{
	scanf("%d",&n);
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		int x,y,v;
		cin>>x>>y>>v;
		if(!x||!y)
			continue;
		build(x,y,v);build(y,x,v);
	}
	DP(1);
	for(int i=1;i<=top;++i)
		calc(sss[i],0);
	for(int i=1;i<=top;++i)
	{
		sum+=BBA[i-1];
		u1[i]=max(u1[i-1],sum+F[sss[i]]);
		v1[i]=max(v1[i-1],sum+F[sss[i]]+Mx);
		Mx=max(Mx,F[sss[i]]-sum);
	}
	ll tt=BBA[top];Mx=sum=BBA[top]=0;
	for(int i=top;i>=1;--i)
	{
		sum+=BBA[i];
		U[i]=max(U[i+1],sum+F[sss[i]]);
		V[i]=max(V[i+1],sum+F[sss[i]]+Mx);
		Mx=max(Mx,F[sss[i]]-sum);
	}
	ll Mini=v1[top];
	for(int i=1;i<top;++i)
		Mini=min(Mini,max(max(v1[i],V[i+1]),tt+u1[i]+U[i+1]));
	ans=max(ans,Mini);
	cout<<ans;
}
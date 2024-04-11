#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,P=1e9+7;

ll ans=1;

int n,to[N],dc,low[N],dfn[N],inst[N];

stack<int>st;

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

void tarjan(int i)
{
	low[i]=dfn[i]=++dc;
	st.push(i);
	inst[i]=true;
	int v=to[i];
	if(!dfn[v])
	{
		tarjan(v);	
		low[i]=min(low[i],low[v]);
	}
	else
	if(inst[v])
		low[i]=min(low[i],dfn[v]);
	if(low[i]==dfn[i])
	{
		int x=0;
		int tot=0;
		do
		{
			x=st.top();
			inst[x]=false;
			st.pop();
			tot++;
		}while(x!=i);
		if(tot!=1)
			ans=ans*(qpow(2,tot)-2+P)%P;
		else
			ans=ans*2%P;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&to[i]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	printf("%lld",ans);
}
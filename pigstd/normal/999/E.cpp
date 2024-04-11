#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
const int N=1e4+10;
int n,m,a[N],u[M],v[M],tag[M],tag2[M];

struct Stack
{
	int a[M],tp;
	int top(){return a[tp];}
	void push(int k){a[++tp]=k;}
	void pop(){tp--;}
};


struct edge
{
	int to,next;
}e[M<<1];int cnt,head[N];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}
int t,dfn[N],low[N],vis[N],fa[N],Cnt,sum[N],in[N];
Stack st;
void tarjan(int k)
{
	dfn[k]=low[k]=++t;st.push(k),vis[k]=1;
	for (int i=head[k];i;i=e[i].next)
		if (dfn[e[i].to]==0)
			tarjan(e[i].to),low[k]=min(low[k],low[e[i].to]);
		else if (vis[e[i].to])low[k]=min(low[k],dfn[e[i].to]);
	if (dfn[k]==low[k])
	{
		Cnt++;//cout<<Cnt<<' ';
		while(st.top()!=0&&st.top()!=k)
			vis[st.top()]=0,sum[Cnt]+=a[st.top()],fa[st.top()]=Cnt,st.pop();
		if (st.top()!=0)
			vis[st.top()]=0,sum[Cnt]+=a[st.top()],fa[st.top()]=Cnt,st.pop();
//		puts("");
	}
}
int dis[N];

signed main()
{
	cin>>n>>m;int s;cin>>s;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		add(u[i],v[i]);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])tarjan(i);
//	cout<<Cnt<<endl;
//	for (int i=1;i<=Cnt;i++)cout<<sum[i]<<' ';
//	puts("");
//	for (int i=1;i<=n;i++)cout<<fa[i]<<' ';
//	puts("");
	int ans=0;tag[fa[s]]=1;
	for (int i=1;i<=m;i++)
		if (fa[u[i]]!=fa[v[i]])
			tag[fa[v[i]]]++;
	for (int i=1;i<=n;i++)
		if (!tag2[fa[i]])
			tag2[fa[i]]=1,ans+=tag[fa[i]]==0?1:0;
	cout<<ans<<endl;
	return 0;
}
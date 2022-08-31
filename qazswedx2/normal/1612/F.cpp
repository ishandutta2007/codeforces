#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
set<pair<int,int> > st;
int n,m,q;
inline int query(int u,int v)
{
	return u+v+(st.find(make_pair(u,v))!=st.end());
}
int G(int x,int y)
{
	x=min(x,n),y=min(y,m);
	if(x==n&&y==m) return 0;
	int q=query(x,y);
	if(x==n) return G(x,q)+1;
	if(y==m) return G(q,y)+1;
	if(x>y) return G(x,q)+1;
	return G(q,y)+1;
}
int F(int x,int y)
{
	x=min(x,n),y=min(y,m);
	if(x==n&&y==m) return 0;
	int q=query(x,y),ans=0;
	if(x==n) return F(x,q)+1;
	if(y==m) return F(q,y)+1;
	if(x>y)
	{
		ans=F(x,q);
		if(x-y<=5) ans=min(ans,F(q,y));
		else ans=min(ans,G(q,y));
		return ans+1;
	}
	else
	{
		ans=F(q,y);
		if(y-x<=5) ans=min(ans,F(x,q));
		else ans=min(ans,G(x,q));
		return ans+1;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		st.insert(make_pair(u,v));
	}
	printf("%d\n",F(1,1));
	return 0;
}
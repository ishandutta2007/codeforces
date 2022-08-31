#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef set<int>::iterator it;
int t,n,sum[1000005],lazy[1000005],tans[200005][2],tt;
int /*q[26][100005],head[26],tail[26],*/c[200005],ct;
char s[200005];
set<int> st,f[26],g[26];
void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
}
void col(int x)
{
	lazy[x]=1;
	sum[x]=0;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2);
		col(x*2+1);
		lazy[x]=0;
	}
}
void modify(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr);
	modify(x*2+1,mid+1,r,ql,qr);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr);
	q2=query(x*2+1,mid+1,r,ql,qr);
	return q1+q2;
}
void print(int l,int r)
{
	int tl=query(1,1,n,1,l-1)+1,tr=query(1,1,n,1,r);
//	printf("l=%d,r=%d,tl=%d,tr=%d\n",l,r,tl,tr);
	modify(1,1,n,l,r);
	tans[++tt][0]=tl;
	tans[tt][1]=tr;
}
void del(int x)
{
	st.erase(x);
	f[s[x]-'a'].erase(x);
	g[s[x]-'a'].erase(x);
}
void upd(int x)
{
	it nw=st.find(x);
	int val=s[x]-'a';
	g[val].erase(x);
	if(nw!=st.begin())
	{
		nw--;
		if(s[*nw]!=s[x]) g[val].insert(x);
		nw++;
	}
	if(nw!=st.end())
	{
		nw++;
		if(nw!=st.end()&&s[*nw]!=s[x]) g[val].insert(x);
	}
}
void build(int x,int l,int r)
{
	lazy[x]=0;
	if(l==r)
	{
		sum[x]=1;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		st.clear();
		scanf("%s",s+1);
		n=strlen(s+1);
		build(1,1,n);
		for(int i=0;i<26;i++)
			g[i].clear(),f[i].clear();
		ct=0;
		for(int i=1;i<n;i++)
			if(s[i]==s[i+1])
			{
				st.insert(i);
				//q[s[i]-'a'][++tail[s[i]-'a']]=i; 
				f[s[i]-'a'].insert(i);
				c[++ct]=i;
				/*if(ct>1)
				{
					g[s[i]-'a'][s[c[ct-1]]-'a'].insert(c[ct-1]);
					g[s[c[ct-1]]-'a'][s[i]-'a'].insert(c[ct-1]);
				}*/
				if(ct>1&&s[c[ct]]!=s[c[ct-1]])
				{
					g[s[i]-'a'].insert(i);
					g[s[c[ct-1]]-'a'].insert(c[ct-1]);
				//	printf("i=%d,c=%d\n",i,c[ct-1]);
				}
			}
		while(1)
		{
			int mx=0,id=0;
			for(int i=0;i<26;i++)
				if((int)f[i].size()>mx)
				{
					mx=f[i].size();
					id=i;
				}
			if(!mx) break;
			if(g[id].empty())
			{
				int las=1;
				for(it i=st.begin();i!=st.end();i++)
					print(las,*i),las=*i+1;
				break;
			}
			int u=*g[id].begin(),v;
		//	printf("u=%d\n",u);
			it nw=st.lower_bound(u);
			if(nw!=st.begin())
			{
				nw--;
				if(s[*nw]!=s[u]) v=*nw;
				else v=u,u=*++(++nw);
			}
			else v=u,u=*++nw;
		/*	printf("id=%d,u=%d,v=%d,nw=%d\n",id,u,v,*nw);
			for(it i=st.begin();i!=st.end();i++)
				printf("%d ",*i);
			printf("\n");*/
			print(v+1,u);
			del(u),del(v);
			nw=st.upper_bound(u);
			if(nw!=st.end()) upd(*nw);
			if(nw!=st.begin()) upd(*--nw);
		}
		print(1,n);
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)
			printf("%d %d\n",tans[i][0],tans[i][1]);
	}
	return 0;
}
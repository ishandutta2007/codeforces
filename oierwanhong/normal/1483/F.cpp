#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011;
namespace BIT
{
	int t[MAXN];
#define lowb (i&-i)
	void modify(int i,int k)
	{
		while(i<MAXN)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}
int tag[MAXN];
namespace SAM
{
	int t[MAXN][26],pre[MAXN],len[MAXN];
	int last=1,tot=1;
	void extend(int w)
	{
		if(t[last][w])
		{
			int nxt=t[last][w];
			if(len[nxt]==len[last]+1)last=nxt;
			else
			{
				int tmp=++tot;
				len[tmp]=len[last]+1,memcpy(t[tmp],t[nxt],sizeof t[nxt]);
				pre[tmp]=pre[nxt],pre[nxt]=tmp;
				while(last&&t[last][w]==nxt)t[last][w]=tmp,last=pre[last];
				last=tmp;
			}
			return;
		}
		int pos=last,cur=++tot;
		len[cur]=len[pos]+1,last=cur;
		while(pos&&!t[pos][w])t[pos][w]=cur,pos=pre[pos];
		if(!pos){pre[cur]=1;return;}
		int nxt=t[pos][w];
		if(len[nxt]==len[pos]+1)pre[cur]=nxt;
		else
		{
			int tmp=++tot;
			len[tmp]=len[pos]+1,memcpy(t[tmp],t[nxt],sizeof t[nxt]);
			pre[tmp]=pre[nxt],pre[cur]=pre[nxt]=tmp;
			while(pos&&t[pos][w]==nxt)t[pos][w]=tmp,pos=pre[pos];
		}
	}
	std::vector<int>g[MAXN];
	int dfn[MAXN],size[MAXN], cur=0;
	void dfs(int u)
	{
		dfn[u]=++cur,size[u]=1;
		for(auto v:g[u])
		{
			if(!tag[v])tag[v]=tag[u];
			dfs(v),size[u]+=size[v];
		}
	}
	void build()
	{
		for(int i=2;i<=tot;++i)g[pre[i]].push_back(i);
		dfs(1);
	}
	int Query(int u){return BIT::Qsum(dfn[u]+size[u]-1)-BIT::Qsum(dfn[u]-1);}
}
char a[MAXN];
int len[MAXN],ed[MAXN], st[MAXN],left[MAXN],trash[MAXN];
bool used[MAXN],intr[MAXN];
int cnt[MAXN];
int main()
{
	int n=read(),all=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a+all);
		all+=strlen(a+all);
		len[i]=all;
		SAM::last=1;
		for(int j=len[i-1];j<len[i];++j)SAM::extend(a[j]-'a');
		ed[i]=SAM::last,tag[ed[i]]=ed[i];
	}
	SAM::build();
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		//printf("I=%d\n",i);
		int top=0,u=1,cur=0,tr=0;
		for(int j=len[i-1];j<len[i];++j)
		{
			u=SAM::t[u][a[j]-'a'];
			if(j==len[i]-1)u=SAM::pre[u];
			//printf("u=%d,t=%d\n",u,tag[u]);
			if(!tag[u])continue;
			int tp=j-(SAM::len[tag[u]]);
			while(top&&left[top]>=tp)trash[++tr]=st[top], intr[st[top]]=1,--top;
			st[++top]=tag[u],left[top]=tp,used[tag[u]]=1;
			++cnt[tag[u]], BIT::modify(SAM::dfn[tag[u]],1);
		}
		for(int j=1;j<=top;++j)
			if(used[st[j]]&&!intr[st[j]])
			{
				//printf("Sig=%d,cnt=%d\n",SAM::Query(st[j]),cnt[st[j]]);
				if(SAM::Query(st[j])==cnt[st[j]])used[st[j]]=0,++cur;
			}
		u=1;
		for(int j=len[i-1];j<len[i];++j)
		{
			u=SAM::t[u][a[j]-'a'];
			if(j==len[i]-1)u=SAM::pre[u];
			if(tag[u])--cnt[tag[u]], BIT::modify(SAM::dfn[tag[u]],-1);
		}
		//printf("F[%d]=%d\n",i,cur);
		ans+=cur;
		while(tr)intr[trash[tr--]]=0;
	}
	printf("%d\n",ans);
	return 0;
}
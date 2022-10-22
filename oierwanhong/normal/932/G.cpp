#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,mod = 1e9+7;
inline int S(int x){return x<mod?x:x-mod;}
char s[MAXN],tp[MAXN];
int f[MAXN],ed[MAXN];
namespace PTree
{
	int t[MAXN][26],fail[MAXN],len[MAXN],top[MAXN],sig[MAXN];
	int last,tot,now;
	void init(){last=tot=1,len[0]=-1,top[0]=0;}
	int extend(int w)
	{
		int pos=last;
		while(pos&&s[now-len[pos]]-'a'!=w)pos=fail[pos];
		if(!t[pos][w])
		{
			t[pos][w]=++tot,len[tot]=len[pos]+2;
			if(!pos)fail[tot]=1,top[tot]=tot;
			else
			{
				pos=fail[pos];
				while(pos&&s[now-len[pos]]-'a'!=w)pos=fail[pos];
				fail[tot]=t[pos][w];
				top[tot]=(len[tot]-len[fail[tot]]==len[fail[tot]]-len[fail[fail[tot]]]?top[fail[tot]]:tot);
			}
			last=tot;
		}
		else last=t[pos][w];
		++now;
		return last;
	}
	void solve()
	{
		//for(int i=1;i<=tot;++i)printf("%d,fail=%d,top=%d\n",i,fail[i],top[i]);
		int n=now;
		f[0]=1;
		for(int i=1;i<=n;++i)
			for(int x=ed[i];x>1;x=fail[top[x]])
			{
				sig[x]= top[x]==x?f[i-len[x]]:S(sig[fail[x]]+f[i-len[top[x]]]);
				if(!(i&1))f[i]=S(f[i]+sig[x]);
			}
		printf("%d\n",f[n]);
	}
}
int main()
{
	scanf("%s",tp+1);
	int n=strlen(tp+1);
	for(int i=1;i<=(n>>1);++i)s[2*i-1]=tp[i];
	for(int i=n;i>(n>>1);--i)s[2*(n-i+1)]=tp[i];
	PTree::init();
	for(int i=1;i<=n;++i)ed[i]=PTree::extend(s[i]-'a');
	PTree::solve();
	return 0;
}
#include<bits/stdc++.h>
#define sz 1000020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,Q;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t){edge[++ecnt]=(hh){t,head[f]};head[f]=ecnt;}
int dfn[sz],low[sz],T;
void dfs(int x)
{
	dfn[x]=++T;
	for (int i=head[x];i;i=edge[i].nxt) dfs(edge[i].t);
	low[x]=T;
}

int tr[sz];
void add(int x,int w){while (x<=T) tr[x]+=w,x+=(x&(-x));}
void add(int l,int r,int w){add(l,w);add(r+1,-w);}
int query(int x){int ret=0;while (x) ret+=tr[x],x-=(x&(-x));return ret;}

bool End[sz];
int p[sz];
int fail[sz],ch[sz][26],cnt;
int insert(string s)
{
	int x=0;
	for (int i=0;i<s.size();i++)
	{
		int &v=ch[x][s[i]-'a'];
		if (!v) v=++cnt;
		x=v;
	}
	End[x]=1;
	return x;
}
void get_fail()
{
	queue<int>q;
	for (int i=0;i<26;i++) if (ch[0][i]) {q.push(ch[0][i]);make_edge(0,ch[0][i]);}
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<26;i++)
		{
			int &v=ch[x][i];
			if (v) fail[v]=ch[fail[x]][i],make_edge(fail[v],v),q.push(v);
			else v=ch[fail[x]][i];
		}
	}
}
void init(){dfs(0);for (int i=1;i<=n;i++) add(dfn[p[i]],low[p[i]],1);}
ll query(string s)
{
	ll ret=0;
	int x=0;
	for (int i=0;i<s.size();i++)
	{
		x=ch[x][s[i]-'a'];
		ret+=(ll)query(dfn[x]);
	}
	return ret;
}
int main()
{
	file();
	int i,x;
	read>>Q>>n;
	string s;
	char c;
	for (i=1;i<=n;i++) getline(cin,s),p[i]=insert(s);
	get_fail();init();
	while (Q--)
	{
		cin>>c;
		if (c=='?') getline(cin,s),printf("%lld\n",query(s));
		else 
		{
			read>>x;
			if (c=='+'&&!End[p[x]]) add(dfn[p[x]],low[p[x]],1),End[p[x]]=1;
			if (c=='-'&&End[p[x]]) add(dfn[p[x]],low[p[x]],-1),End[p[x]]=0;
		}
	}
}
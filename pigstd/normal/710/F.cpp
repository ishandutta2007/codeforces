#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=3e5+10;
int q,val[M],tot;
string s[M];
pii p[M];int top;

struct tree{int son[27],val,fail;}P;
struct node
{
	vector<tree>v;int tot;
	vector<int>e[M];
	void insert(string s,int V)
	{
		int now=0;
//		cout<<s<<endl;
		for (int i=0;i<s.size();i++)
		{
			int c=s[i]-'a'+1;
			if (!v[now].son[c])v[now].son[c]=++tot,v.pb(P);
			now=v[now].son[c];
		}
		v[now].val+=V;
	}
	void dfs(int u)
	{
		for (auto to:e[u])v[to].val+=v[u].val,dfs(to);
	}
	void get(int l,int r)
	{
		v.clear();v.pb(P);
		for (int i=0;i<=tot;i++)e[i].clear();
		tot=0;
		for (int i=l;i<=r;i++)insert(s[i],val[i]);
		queue<int>q;
		for (int i=1;i<=26;i++)
			if (v[0].son[i])q.push(v[0].son[i]);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for (int i=1;i<=26;i++)
			{
				int now=v[u].son[i];
				if (!now)v[u].son[i]=v[v[u].fail].son[i];
				else v[now].fail=v[v[u].fail].son[i],q.push(now);
			}
		}
		for (int i=1;i<=tot;i++)e[v[i].fail].pb(i);//,cout<<i<<' '<<v[i].fail<<' '<<v[i].val<<'\n';
		dfs(0);
	}
	int solve(string s)
	{
		int now=0,res=0;
		for (int i=0;i<s.size();i++)
		{
			int c=s[i]-'a'+1;
			now=v[now].son[c];res+=v[now].val;
//			cout<<now<<' '<<v[now].val<<' ';
		}return res;
	}
}T[25];

signed main()
{
	WT
	{
		int opt=read();
		if (opt==1||opt==2)
		{
			tot++;cin>>s[tot];
			val[tot]=(opt==1?1:-1);
			int L=tot;
			while(top!=0&&p[top].y-p[top].x==tot-L)
				L=p[top].x,top--;
			p[++top]=mp(L,tot);
			T[top].get(L,tot);
		}
		else
		{
			string s;cin>>s;int ans=0;
			for (int i=1;i<=top;i++)ans+=T[i].solve(s);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
6
1 abc
1 bcd
1 abcd
3 abcd
2 abcd
3 abcd
*/
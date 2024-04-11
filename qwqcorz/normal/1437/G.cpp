#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
namespace AC_automation
{
	struct trie
	{
		int son[26],fail;
		multiset<int>val;
	}t[N];
	int getmax(int x)
	{
		if (t[x].val.empty()) return -1;
		return *t[x].val.rbegin();
	}
	int cnt=1;
	int insert(char *a)
	{
		int now=1,len=strlen(a+1);
		for (int i=1;i<=len;i++)
		{
			if (!t[now].son[a[i]-'a']) t[now].son[a[i]-'a']=++cnt;
			now=t[now].son[a[i]-'a'];
		}
		t[now].val.insert(0);
		return now;
	}
	int q[N];
	void build()
	{
		t[1].fail=1;
		int he=1,ta=0;
		for (int i=0;i<26;i++)
		if (t[1].son[i])
		{
			t[t[1].son[i]].fail=1;
			q[++ta]=t[1].son[i];
		}
		else t[1].son[i]=1;
		while (he<=ta)
		{
			int now=q[he++];
			for (int i=0;i<26;i++)
			if (t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q[++ta]=t[now].son[i];
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}
namespace LCT
{
	#define ls son[0]
	#define rs son[1]
	struct node
	{
		int son[2],fa,mx,val;
		bool tag;
	}t[N*26];
	void rev(int w) {swap(t[w].ls,t[w].rs),t[w].tag^=1;}
	void push_up(int w) {t[w].mx=max(max(t[t[w].ls].mx,t[t[w].rs].mx),t[w].val);}
	void push_down(int w)
	{
		if (!t[w].tag) return;
		rev(t[w].ls);
		rev(t[w].rs);
		t[w].tag=0;
	}
	bool isroot(int x) {return t[t[x].fa].ls!=x&&t[t[x].fa].rs!=x;}
	bool where(int x) {return t[t[x].fa].rs==x;}
	void connect(int x,int y,bool s) {t[x].fa=y,t[y].son[s]=x;}
	void rotate(int x)
	{
		int y=t[x].fa,R=t[y].fa;
		int wx=where(x),wy=where(y);
		int B=t[x].son[!wx];
		if (!isroot(y)) connect(x,R,wy);
				   else t[x].fa=R;
		connect(B,y,wx);
		connect(y,x,!wx);
		push_up(y);
		push_up(x);
	}
	void splay(int x)
	{
		int top=0,tmp=x;
		static int st[N];
		while (!isroot(tmp)) st[++top]=tmp,tmp=t[tmp].fa;
		while (top) push_down(st[top--]);
		for (;!isroot(x);rotate(x))
		if (!isroot(t[x].fa))
		rotate(where(x)==where(t[x].fa)?t[x].fa:x);
	}
	void access(int x)
	{
		for (int y=0;x;y=x,x=t[x].fa)
		splay(x),t[x].rs=y,push_up(x);
	}
	#undef ls
	#undef rs
}
int pos[N],val[N];
char a[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		pos[i]=AC_automation::insert(a);
	}
	AC_automation::build();
	LCT::t[0].mx=-1;
	for (int i=1;i<=AC_automation::cnt;i++)
		LCT::t[i].fa=AC_automation::t[i].fail,
		LCT::t[i].mx=LCT::t[i].val=AC_automation::getmax(i);
	LCT::t[1].fa=0;
	while (m--)
	{
		int opt=read();
		if (opt==1)
		{
			int x=read(),y=read();
			AC_automation::t[pos[x]].val.erase(AC_automation::t[pos[x]].val.find(val[x]));
			val[x]=y;
			AC_automation::t[pos[x]].val.insert(val[x]);
			LCT::splay(pos[x]);
			LCT::t[pos[x]].val=AC_automation::getmax(pos[x]);
			LCT::push_up(pos[x]);
		}
		else
		{
			scanf("%s",a+1);
			int len=strlen(a+1),now=1,ans=-1;
			for (int i=1;i<=len;i++)
			{
				now=AC_automation::t[now].son[a[i]-'a'];
				LCT::access(now);
				LCT::splay(now);
				ans=max(ans,LCT::t[now].mx);
			}
			print(ans);
		}
	}
	
	return 0;
}
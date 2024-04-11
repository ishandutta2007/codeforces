#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int ls,rs;
	int op;
	int fa;
	//1:&
	//2:|
	//3:^
	//4:!
	int val;
	int ans[2];
}t[N];
string s;
int p[N],cnt=0;
void init()
{
	for (int i=1;i<N;i++)
	{
		t[i].ans[0]=t[i].ans[1]=-1;
		t[i].ls=t[i].rs=0;
		t[i].op=0;
		t[i].val=-1;
	}
	char c;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		s="";
		c=getchar();
		while ('A'<=c&&c<='Z')
		{
			s=s+c;
			c=getchar();
		}
		if (s=="AND")
		{
			t[i].rs=read();
			t[i].ls=read();
			t[i].op=1;
		}
		if (s=="OR")
		{
			t[i].rs=read();
			t[i].ls=read();
			t[i].op=2;
		}
		if (s=="XOR")
		{
			t[i].rs=read();
			t[i].ls=read();
			t[i].op=3;
		}
		if (s=="NOT")
		{
			t[i].ls=read();
			t[i].op=4;
		}
		if (s=="IN")
		{
			t[i].val=read();
			p[++cnt]=i;
		}
	}
}
void dfs0(int w,int father)
{
	t[w].fa=father;
	if (w==0||t[w].val>=0) return;
	dfs0(t[w].ls,w);
	dfs0(t[w].rs,w);
	if (t[w].op==1) t[w].val=t[t[w].ls].val&&t[t[w].rs].val;
	if (t[w].op==2) t[w].val=t[t[w].ls].val||t[t[w].rs].val;
	if (t[w].op==3) t[w].val=t[t[w].ls].val^ t[t[w].rs].val;
	if (t[w].op==4) t[w].val=!t[t[w].ls].val;
}
void dfs1(int w)
{
	if (!w) return;
	if (t[w].fa)
	{
		int br;
		if (t[t[w].fa].ls==w) br=t[t[w].fa].rs;
		if (t[t[w].fa].rs==w) br=t[t[w].fa].ls;
		br=t[br].val;
		int val=0;
		if (t[t[w].fa].op==1) val=val&&br;
		if (t[t[w].fa].op==2) val=val||br;
		if (t[t[w].fa].op==3) val=val^ br;
		if (t[t[w].fa].op==4) val=!val;
		t[w].ans[0]=t[t[w].fa].ans[val];
		val=1;
		if (t[t[w].fa].op==1) val=val&&br;
		if (t[t[w].fa].op==2) val=val||br;
		if (t[t[w].fa].op==3) val=val^ br;
		if (t[t[w].fa].op==4) val=!val;
		t[w].ans[1]=t[t[w].fa].ans[val];
	}
	else
	{
		t[w].ans[0]=0;
		t[w].ans[1]=1;
	}
	dfs1(t[w].ls);
	dfs1(t[w].rs);
}

int main()
{
	init();
	dfs0(1,0);
	dfs1(1);
	for (int i=1;i<=cnt;i++) putchar('0'+t[p[i]].ans[!t[p[i]].val]);

	return 0;
}
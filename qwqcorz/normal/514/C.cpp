#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;

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
char a[N];
struct trie
{
	bool ed;
	int son[3];
}t[N];
int cnt=0,len;
void add(int now,int i)
{
	if (i>len) return void(t[now].ed=1);
	if (!t[now].son[a[i]-'a']) t[now].son[a[i]-'a']=++cnt;
	add(t[now].son[a[i]-'a'],i+1);
}
bool query(int now,int i,bool turn)
{
	if (i>len) return t[now].ed&&turn;
	if (t[now].son[a[i]-'a'])
	if (query(t[now].son[a[i]-'a'],i+1,turn)) return 1;
	if (!turn)
	for (int j=0;j<3;j++)
	if (a[i]-'a'!=j&&t[now].son[j])
	if (query(t[now].son[j],i+1,1))
	return 1;
	return 0;
}

signed main()
{
	memset(t,0,sizeof(t));
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		len=strlen(a+1);
		add(0,1);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",a+1);
		len=strlen(a+1);
		puts(query(0,1,0)?"YES":"NO");
	}

	return 0;
}
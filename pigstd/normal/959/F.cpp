#include<bits/stdc++.h>
using namespace std;

const int Mod=1e9+7;
const int M=1e5+10;
int n,m,ans[M],a[M],pow2[M];

struct xxj
{
	int tot,a[25];
	void insert(int x)
	{
		for (int i=22;i>=0;i--)
			if ((1<<i)&x)
			{
				if (a[i])x^=a[i];
				else {a[i]=x,tot++;break;}
			}
	}
	bool check(int x)
	{
		for (int i=22;i>=0;i--)
			if ((1<<i)&x)
			{
				if (a[i])x^=a[i];
				else return 0;
			}
		return 1;
	}
}T;

struct query
{
	int id,l,x;
}q[M];

bool cmp(query a,query b){return a.l<b.l;}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void init(int x)
{
	pow2[0]=1;
	for (int i=1;i<=x;i++)pow2[i]=pow2[i-1]*2%Mod;
}

int main()
{
	n=read(),m=read();init(n);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)
		q[i].l=read(),q[i].x=read(),q[i].id=i;
	sort(q+1,q+1+m,cmp);int l=0;
	for (int i=1;i<=m;i++)
	{
		while(l<q[i].l)T.insert(a[++l]);
		if (T.check(q[i].x))ans[q[i].id]=pow2[l-T.tot];
	}
	for (int i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}
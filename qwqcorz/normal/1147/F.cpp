#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N][N],id[N][N];
int w1[N],w2[N];
queue<int>q;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		a[i][j]=read();
		cout<<"B"<<endl;
		char c;
		cin>>c;
		int x=read();
		if ((c=='D')^(x>n))
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		a[i][j]=n*n-a[i][j];
		for (int i=1;i<=n;i++)
		{
			q.push(i);
			w1[i]=w2[i]=0;
			for (int j=1;j<=n;j++) id[i][j]=j;
			sort(id[i]+1,id[i]+1+n,[&](int x,int y){return a[i][x]<a[i][y];});
		}
		while (!q.empty())
		{
			int now=q.front();
			q.pop();
			#define to id[now][i]
			for (int i=1;i<=n;i++)
			if (!w2[to]||a[now][to]>a[w2[to]][to])
			{
				if (w2[to]) q.push(w2[to]);
				w1[now]=to;
				w2[to]=now;
				break;
			}
			#undef to
		}
		do
		{
			cout<<(x<=n?w1[x]+n:w2[x-n])<<endl;
			x=read();
		}while (x>=0);
	}

	return 0;
}
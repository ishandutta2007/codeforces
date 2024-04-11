#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int Q=3e5+5;

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
bitset<N>a[N];
vector<int>nxt[Q];
bool tag[N],flag[Q];
int qry[Q][3],sum[N],ans[Q],n,m,q;
void solve(int now,int tot,bool ck)
{
	if (now>q||(flag[now]&&!ck)) return;
	int last,lsum,ltot=tot,x=qry[now][1],y=qry[now][2];
	if (qry[now][0]==1)
	{
		lsum=sum[x];
		last=a[x][y];
		tot+=1-(a[x][y]^tag[x]);
		sum[x]+=1-(a[x][y]^tag[x]);
		a[x][y]=1^tag[x];
	}
	if (qry[now][0]==2)
	{
		lsum=sum[x];
		last=a[x][y];
		tot-=a[x][y]^tag[x];
		sum[x]-=a[x][y]^tag[x];
		a[x][y]=tag[x];
	}
	if (qry[now][0]==3)
	{
		tot+=m-sum[x]*2;
		sum[x]=m-sum[x];
		tag[x]^=1;
	}
//	print(now,' ');
//	print(tot);
	ans[now]=tot;
	solve(now+1,tot,0);
	for (int i=0;i<nxt[now].size();i++) solve(nxt[now][i],tot,1);
	tot=ltot;
	if (qry[now][0]==1||qry[now][0]==2)
	{
		sum[x]=lsum;
		a[x][y]=last;
	}
	if (qry[now][0]==3)
	{
		sum[x]=m-sum[x];
		tag[x]^=1;
	}
}

int main()
{
	qry[0][0]=0;
	n=read();
	m=read();
	q=read();
	for (int i=1;i<=n;i++) sum[i]=tag[i]=0;
	for (int i=0;i<=q;i++) flag[i]=0;
	for (int i=0;i<=q;i++) ans[i]=-1;
	for (int i=0;i<=q;i++) nxt[i].clear();
	for (int i=1;i<=q;i++)
	{
		qry[i][0]=read();
		qry[i][1]=read();
		if (qry[i][0]<=2) qry[i][2]=read();
		if (qry[i][0]==4)
		{
			flag[i]=1;
			nxt[qry[i][1]].push_back(i);
		}
	}
	solve(0,0,0);
	for (int i=1;i<=q;i++) print(ans[i]);

	return 0;
}
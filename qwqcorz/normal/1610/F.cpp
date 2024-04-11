#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=3e6+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,id,st,ed;
    bool fs,ft;
};
bool del[M*2];
int u[M],v[M],w[M],ans[M],nxt[M];
int cnt,sum[N];
vector<edge>e[2][N];
vector<int>to[M];
vector<pair<edge,edge>>tmp[2];
void ACDC(int i,int now,vector<edge>&a)
{
	while ((int)a.size()>1)
	{
		edge x=a.back(); a.pop_back();
		while (!a.empty()&&del[x.id]) x=a.back(),a.pop_back();
		if (a.empty())
		{
			if (!del[x.id]) a.push_back(x);
			break;
		}
		edge y=a.back(); a.pop_back();
		while (!a.empty()&&del[y.id]) y=a.back(),a.pop_back();
		if (del[y.id])
		{
			a.push_back(x);
			break;
		}
		del[x.id]=del[y.id]=1;
		to[x.st].push_back(y.st);
		to[y.st].push_back(x.st);
		if (x.to==y.to){tmp[i].push_back(make_pair(x,y));continue;}
		cnt++;
		e[i][x.to].push_back((edge){y.to,cnt,x.ed,y.ed,!x.ft,y.ft});
		e[i][y.to].push_back((edge){x.to,cnt,y.ed,x.ed,!y.ft,x.ft});
	}
}
void asdf(int s,int t,int f)
{
	int lst=0;
	while (1)
	{
		ans[s]=f;
		sum[f==1?u[s]:v[s]]+=2-w[s];
		sum[f==1?v[s]:u[s]]-=2-w[s];
		if (s==t) break;
		int nxt=0;
		for (int i:to[s]) if (i!=lst) nxt=i;
		f=(f==1?v[s]:u[s])==u[nxt]?1:0;
		lst=s,s=nxt;
	}
}
void dfs(int now)
{
	for (int j=0;j<=1;j++)
	while (!e[j][now].empty())
	{
		edge i=e[j][now].back();
		e[j][now].pop_back();
		if (del[i.id]) continue;
		del[i.id]=1;
		asdf(i.st,i.ed,i.fs);
		dfs(i.to);
	}
}
void GreenDay()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read()%2;
		::u[i]=u,::v[i]=v,::w[i]=w;
		cnt++;
		e[w][u].push_back((edge){v,cnt,cnt,cnt,1,1});
		e[w][v].push_back((edge){u,cnt,cnt,cnt,0,0});
	}
	for (int i=0;i<=1;i++)
	for (int j=1;j<=n;j++)
	ACDC(i,j,e[i][j]);
	for (int i=0;i<=1;i++)
	while (!tmp[i].empty())
	{
		edge x=tmp[i].back().first,y=tmp[i].back().second;
		tmp[i].pop_back();
		cnt++;
		e[i][x.to].push_back((edge){y.to,cnt,x.ed,y.ed,!x.ft,y.ft});
		e[i][y.to].push_back((edge){x.to,cnt,y.ed,x.ed,!y.ft,x.ft});
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
		{
			vector<edge>tmp;
			tmp.swap(e[j][i]);
			for (edge k:tmp) if (!del[k.id])
			{
				if (k.to==i){asdf(k.st,k.ed,k.fs),del[k.id]=1;continue;}
				e[j][i].push_back(k);
			}
		}
		if ((int)(e[0][i].size()+e[1][i].size())==1) dfs(i);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
		{
			vector<edge>tmp;
			tmp.swap(e[j][i]);
			for (edge k:tmp) if (!del[k.id])
			{
				if (k.to==i){asdf(k.st,k.ed,k.fs),del[k.id]=1;continue;}
				e[j][i].push_back(k);
			}
		}
		if ((int)(e[0][i].size()+e[1][i].size())==2) dfs(i);
	}
	int answer=0;
	for (int i=1;i<=n;i++) answer+=abs(sum[i])==1;
	print(answer);
	for (int i=1;i<=m;i++) putchar(ans[i]?'1':'2');
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=1e5+10;
int n,p1[M],p2[M],x[M],y[M],c[M],sum1[M][3],sum2[M][3],cnt1,cnt2,res;
vector<int>e1[3][M],e2[3][M];
map<int,int>t1,t2;
struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void clear(){memset(c,0,sizeof(c));}
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
}T[3];

void ckmax(int &a,int b){a=a>b?a:b;}
int min(int a,int b,int c){return min(a,min(b,c));}

void work(int a,int b,int c)
{
	for (int i=1,l=1;i<=n;i++)
	{
		while(l+1<=n&&sum1[l+1][b]-sum1[i][b]<=sum1[n][c]-sum1[l+1][c])l++;
		ckmax(res,min(sum1[l][b]-sum1[i][b],sum1[i][a],sum1[n][c]-sum1[l][c]));
		if (l+1<=n)
			ckmax(res,min(sum1[l+1][b]-sum1[i][b],sum1[i][a],sum1[n][c]-sum1[l+1][c]));
	}
	for (int i=1,l=1;i<=n;i++)
	{
		while(l+1<=n&&sum2[l+1][b]-sum2[i][b]<=sum2[n][c]-sum2[l+1][c])l++;
		ckmax(res,min(sum2[l][b]-sum2[i][b],sum2[i][a],sum2[n][c]-sum2[l][c]));
		if (l+1<=n)
			ckmax(res,min(sum2[l+1][b]-sum2[i][b],sum2[i][a],sum2[n][c]-sum2[l+1][c]));
	}int now=n/3;T[b].clear(),T[c].clear();
	for (int i=1;i<=n;i++)
	{
		now-=e1[a][i].size();
		for (auto x:e1[b][i])T[b].add(x,1);
		for (auto x:e1[c][i])T[c].add(x,1);
		int k=0,now1=0,now2=T[c].ask(n);
		for (int j=20;j>=0;j--)
			if ((k+(1<<j))<=n&&now1+T[b].c[k+(1<<j)]<=now2-T[c].c[k+(1<<j)])
				k+=1<<j,now1+=T[b].c[k],now2-=T[c].c[k];
		ckmax(res,min(now,now1,now2));
		if (k!=n)ckmax(res,min(now,T[b].ask(k+1),T[c].ask(n)-T[c].ask(k+1)));
	}now=n/3;T[b].clear(),T[c].clear();
	for (int i=n;i>=1;i--)
	{
		now-=e1[a][i].size();
		for (auto x:e1[b][i])T[b].add(x,1);
		for (auto x:e1[c][i])T[c].add(x,1);
		int k=0,now1=0,now2=T[c].ask(n);
		for (int j=20;j>=0;j--)
			if ((k+(1<<j))<=n&&now1+T[b].c[k+(1<<j)]<=now2-T[c].c[k+(1<<j)])
				k+=1<<j,now1+=T[b].c[k],now2-=T[c].c[k];
		ckmax(res,min(now,now1,now2));
		if (k!=n)ckmax(res,min(now,T[b].ask(k+1),T[c].ask(n)-T[c].ask(k+1)));
	}now=n/3;T[b].clear(),T[c].clear();
	for (int i=1;i<=n;i++)
	{
		now-=e2[a][i].size();
		for (auto x:e2[b][i])T[b].add(x,1);
		for (auto x:e2[c][i])T[c].add(x,1);
		int k=0,now1=0,now2=T[c].ask(n);
		for (int j=20;j>=0;j--)
			if ((k+(1<<j))<=n&&now1+T[b].c[k+(1<<j)]<=now2-T[c].c[k+(1<<j)])
				k+=1<<j,now1+=T[b].c[k],now2-=T[c].c[k];
		ckmax(res,min(now,now1,now2));
		if (k!=n)ckmax(res,min(now,T[b].ask(k+1),T[c].ask(n)-T[c].ask(k+1)));
	}now=n/3;T[b].clear(),T[c].clear();
	for (int i=n;i>=1;i--)
	{
		now-=e2[a][i].size();
		for (auto x:e2[b][i])T[b].add(x,1);
		for (auto x:e2[c][i])T[c].add(x,1);
		int k=0,now1=0,now2=T[c].ask(n);
		for (int j=20;j>=0;j--)
			if ((k+(1<<j))<=n&&now1+T[b].c[k+(1<<j)]<=now2-T[c].c[k+(1<<j)])
				k+=1<<j,now1+=T[b].c[k],now2-=T[c].c[k];
		ckmax(res,min(now,now1,now2));
		if (k!=n)ckmax(res,min(now,T[b].ask(k+1),T[c].ask(n)-T[c].ask(k+1)));
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)p1[i]=x[i]=read(),p2[i]=y[i]=read(),c[i]=read();
	sort(p1+1,p1+1+n),sort(p2+1,p2+1+n);
	for (int i=1;i<=n;i++)
	{
		if (i==1||p1[i]!=p1[i-1])t1[p1[i]]=++cnt1;
		if (i==1||p2[i]!=p2[i-1])t2[p2[i]]=++cnt2;
	}
	for (int i=1;i<=n;i++)x[i]=t1[x[i]],y[i]=t2[y[i]];
//	for (int i=1;i<=n;i++)cout<<x[i]<<' '<<y[i]<<' '<<c[i]<<endl;
	for (int i=1;i<=n;i++)
		sum1[x[i]][c[i]-1]++,sum2[y[i]][c[i]-1]++,e1[c[i]-1][x[i]].pb(y[i]),e2[c[i]-1][y[i]].pb(x[i]);
	for (int i=1;i<=n;i++)
		sum1[i][0]+=sum1[i-1][0],sum1[i][1]+=sum1[i-1][1],sum1[i][2]+=sum1[i-1][2],
		sum2[i][0]+=sum2[i-1][0],sum2[i][1]+=sum2[i-1][1],sum2[i][2]+=sum2[i-1][2];
	work(0,1,2),work(0,2,1),work(1,0,2),work(1,2,0),work(2,1,0),work(2,0,1);
	cout<<3*res<<endl;
	return 0;
}
/*
 
 
*/
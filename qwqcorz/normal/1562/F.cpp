#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int debug=0;

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
int in[N];
mt19937 rnd(time(0));
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
inline int lcm(int x,int y){return x/gcd(x,y)*y;}
inline int get(int x)
{
	int ret=1;
	for (int i=2;i*i<=x;i++)
	if (x%i==0)
	{
		ret=i;
		while (x%i==0) x/=i;
	}
	if (x>1) return x;
	return ret;
}
int a[N],LCM[105][105],ans[N];
inline int Ask(int x,int y)
{
	printf("? %lld %lld\n",x,y);
	if (debug) return lcm(in[x],in[y]);
	fflush(stdout);
	return read();
}
inline void Answer(int n)
{
	putchar('!');
	for (int i=1;i<=n;i++) printf(" %lld",ans[i]);
	cout<<endl;
}
inline int getmax(int n,int x,int y,int m)
{
	vector<int>vx,vy,vm;
	for (int i=1;i<n;i++) vm.push_back(lcm(m,m-i));
	for (int i=1;i<=n;i++) if (i!=x) vx.push_back(LCM[i][x]);
	sort(vm.begin(),vm.end());
	sort(vx.begin(),vx.end());
	return vm==vx?x:y; 
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) ans[i]=0;
		if (debug) for (int i=1;i<=n;i++) in[i]=read();
		if (n<=100&&debug<2)
		{
			for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			LCM[i][j]=LCM[j][i]=Ask(i,j);
			int x=1,y=1;
			for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			if (LCM[x][y]<LCM[i][j]) x=i,y=j;
			int m=sqrt(LCM[x][y])+1,w=getmax(n,x,y,m);
			ans[w]=m;
			for (int k=m-1;k>=1;k--)
			{
				x=0;
				for (int i=1;i<=n;i++)
				if (!ans[i]&&(!x||LCM[w][x]<LCM[w][i])) x=i;
				ans[w=x]=k;
			}
		}
		else
		{
			int mul=0,p=0,x=0,y=0,u,v;
			for (int i=1;i<=5000;i++)
			{
				do u=rnd()%n+1,v=rnd()%n+1;while (u==v);
				int val=Ask(u,v),pval=get(val);
				if (pval>p) mul=val,p=pval,x=u,y=v;
			}
			int tmp=x==1?2:1,val=Ask(x,tmp),pval=get(val),pos;
			if (pval==p) ans[x]=p,ans[y]=mul/p,pos=x;
					else ans[x]=mul/p,ans[y]=p,pos=y;
			for (int i=1;i<=n;i++) if (!ans[i]) ans[i]=Ask(i,pos)/p;
		}
		Answer(n);
	}
	
	return 0;
}
/*
3
5
8 10 7 6 9
5
28 25 29 27 26
7
1 2 3 4 5 6 7
*/
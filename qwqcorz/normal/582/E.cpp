#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=16;
const int SS=1<<16;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int tr[256];
void ysgs()
{
	tr['A']=0,tr['B']=1,tr['C']=2,tr['D']=3;
	tr['a']=4,tr['b']=5,tr['c']=6,tr['d']=7;
}
char s[N];
char op[N];
int num[N],top1=0,top2=0,cnt=0;
char a[N];
int ls[N],rs[N];
int dp[N][SS],n,st[M][5];
void dftand(int *a,int type)
{
	int lim=1<<n;
	for (int mid=1;mid<lim;mid*=2)
	for (int i=0;i<lim;i+=mid*2)
	for (int j=0;j<mid;j++)
	{
		int x=a[i+j],y=a[i+j+mid];
		if (type>0) a[i+j]=(x+y)%p;
			   else a[i+j]=(x-y+p)%p;
	}
}
void fwtand(int *a,int *x,int *y)
{
	static int f[SS];
	dftand(x,1),dftand(y,1);
	for (int i=0;i<(1<<n);i++) f[i]=1LL*x[i]*y[i]%p;
	dftand(f,-1),dftand(x,-1),dftand(y,-1);
	for (int i=0;i<(1<<n);i++) a[i]=(a[i]+f[i])%p;
}
void dftor(int *a,int type)
{
	int lim=1<<n;
	for (int mid=1;mid<lim;mid*=2)
	for (int i=0;i<lim;i+=mid*2)
	for (int j=0;j<mid;j++)
	{
		int x=a[i+j],y=a[i+j+mid];
		if (type>0) a[i+j+mid]=(y+x)%p;
			   else a[i+j+mid]=(y-x+p)%p;
	}
}
void fwtor(int *a,int *x,int *y)
{
	static int f[SS];
	dftor(x,1),dftor(y,1);
	for (int i=0;i<(1<<n);i++) f[i]=1LL*x[i]*y[i]%p;
	dftor(f,-1),dftor(x,-1),dftor(y,-1);
	for (int i=0;i<(1<<n);i++) a[i]=(a[i]+f[i])%p;
}
void dfs(int now)
{
	if (ls[now])
	{
		dfs(ls[now]),dfs(rs[now]);
		if (a[now]=='?'||a[now]=='&') fwtand(dp[now],dp[ls[now]],dp[rs[now]]);
		if (a[now]=='?'||a[now]=='|') fwtor(dp[now],dp[ls[now]],dp[rs[now]]);
	}
	else
	{
		int l=0,r=7;
		if (a[now]!='?') l=r=tr[(int)a[now]];
		for (int i=l;i<=r;i++)
		{
			int S=0;
			for (int j=0;j<n;j++)
			{
				int x=i<4?st[j][i]:!st[j][i-4];
				S=S<<1|x;
			}
			dp[now][S]++;
		}
	}
}

signed main()
{
	ysgs();
	scanf("%s",s+1);
	int len=strlen(s+1)+1;
	s[0]='(',s[len]=')',s[len+1]='\0';
	for (int i=0;i<=len;i++)
	if (s[i]=='(') op[++top1]='(';
	else if (s[i]==')')
	{
		if (op[top1]!='(')
		{
			a[++cnt]=op[top1];
			ls[cnt]=num[top2-1];
			rs[cnt]=num[top2];
			num[--top2]=cnt;
			top1--;
		}
		top1--;
	}
	else if (i&&s[i-1]==')') op[++top1]=s[i];
	else a[num[++top2]=++cnt]=s[i];
	n=read();
	int S=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<5;j++) st[i][j]=read();
		S=S<<1|st[i][4];
	}
	int rt=num[1];
//	print(rt);
//	for (int i=1;i<=cnt;i++) print(i,':'),print(ls[i],','),print(rs[i]);
//	for (int i=1;i<=cnt;i++) putchar(a[i]);;puts("");
	dfs(rt);
	print(dp[rt][S]);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
inline bool ckmx(int &x,int y){return x<y?(x=y,1):0;}
int a[N];
void output(int n,char opt){for (int i=1;i<=n;i++) print(a[i],i<n?opt:'\n');}
void output(int l,int r,char opt){for (int i=l;i<r;i++) print(a[i],opt);write(a[r]);}
int b[N],v[N],p[N],dp[N],from[N];
void out(int x)
{
	if (from[x]==1) return output(p[1],p[x+1]-1,'*');
	out(from[x]-2);
	for (int i=1;i<=v[from[x]-1];i++) printf("+1");
	putchar('+');
	output(p[from[x]],p[x+1]-1,'*');
}
void solve(int l,int r)
{
	int mul=1,tot=0,n=0;
	while (l<r&&a[l]==1) printf("1+"),l++;
	if (l==r&&a[l]==1) return void(putchar('1'));
	while (a[r]==1) tot++,r--;
	for (int i=l;i<=r;i++)
	{
		if ((mul*=a[i])>=(int)1e6) {output(l,r,'*');while (tot--) printf("+1");return;}
		if (n==0||b[n]!=(a[i]==1)) n++,b[n]=a[i]==1,v[n]=a[i],p[n]=i;
		else if (a[i]==1) v[n]++;
		else v[n]*=a[i];
	}
	for (int i=0;i<=n;i++) dp[i]=0;
//	for (int i=1;i<=n;i++) print(b[i],' '),print(v[i]);
	for (int i=1;i<=n;i++)
	for (int j=i,mul=1;j>=1;j--)
	if (!b[j])
	{
		mul*=v[j];
		if (j==1) {if (ckmx(dp[i],mul)) from[i]=j;}
			 else {if (ckmx(dp[i],mul+v[j-1]+dp[j-2])) from[i]=j;}
	}
//	for (int i=1;i<=n;i++) print(from[i],','),print(dp[i]);
	p[n+1]=r+1;
	out(n);
	while (tot--) printf("+1");
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	string s; cin>>s;
	sort(s.begin(),s.end());
	if ((int)s.length()==1) output(n,s[0]);
	else if (s=="+-") output(n,'+');
	else if (s=="*-")
	{
		int pos=1;
		for (int i=n;i>=1;i--) if (a[i]==0) pos=i;
		for (int i=1;i<=n;i++) print(a[i],i<n?(i+1==pos?'-':'*'):'\n');
	}
	else
	{
		int j=0;
		for (int i=1;i<=n;i++)
		if (a[i]==0)
		{
			if (j) putchar('+');
			if (j+1<=i-1) solve(j+1,i-1),putchar('+');
			putchar('0');
			j=i;
		}
		if (j&&j<n) putchar('+');
		if (j<n) solve(j+1,n);
		puts("");
	}
	
	return 0;
}
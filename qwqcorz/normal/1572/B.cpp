#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
vector<int>ans;
int a[N];
void alb(int x)
{
	int xxx=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=xxx;
	ans.push_back(x);
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		ans.clear();
		int n=read(),A=0,B=0;
		for (int i=1;i<=n;i++) A^=a[i]=read(),B+=!a[i];
		if (A||!B){puts("NO");continue;}
		for (int i=1,tot=0;i<=n;i++)
		if (a[i]) tot++;
		else if (tot&1)
		{
			alb(i-1);
			tot++;
		}
		else tot=0;
		int pos=0;
		for (int i=1;i<=n;i++) if (!a[i]) pos=i;
		if (!pos){puts("NO");continue;}
		for (int i=pos;i>=3;i--) if (a[i-1]) alb(i-2);
		for (int i=pos;i<=n-2;i++) if (a[i+1]) alb(i);
		puts("YES");
		print(ans.size());
		for (int i:ans) print(i,' ');;puts("");
//		for (int i=1;i<=n;i++) print(a[i],",\n"[i==n]);
	}
	
	return 0;
}
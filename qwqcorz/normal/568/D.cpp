#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int N=1e5+5;
const ld eps=1e-8;
 
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int rnd(){return rand()*RAND_MAX+rand();}
struct node
{
	int A,B,C,id;
	bool check(ld x,ld y)
	{
		return abs(x*A+y*B+C)<=eps;
	}
}tmp;
vector<node>a;
int n,k,ansx[7],ansy[7];
void output(int m)
{
	puts("YES");
	print(m);
	for (int i=1;i<=m;i++) print(ansx[i],' '),print(ansx[i]==ansy[i]?-1:ansy[i]);
	exit(0);
}
bool get(ld &x,ld &y,node u,node v)
{
	if (u.B*v.A==u.A*v.B)
	{
		if (u.C==v.C)
		{
			if (u.B) return x=acos(-1)*rand(),y=-1.0*(u.C+x*u.A)/u.B,1;
			return y=acos(-1)*rand(),x=-1.0*(u.C+y*u.B)/u.A,1;
		}
		return 0;
	}
	x=1.0*(u.B*v.C-u.C*v.B)/(u.A*v.B-u.B*v.A);
	y=1.0*(u.A*v.C-u.C*v.A)/(u.B*v.A-u.A*v.B);
	return 1;
}
void dfs(int m,vector<node>a)
{
	if (a.empty()) output(m);
	if (m==k) return;
	vector<node>nxt;
	for (int i=1;i<=(5-m)*(5-m);i++)
	{
		ld x,y;
		int u=rnd()%a.size(),v=rnd()%a.size();
		if (!get(x,y,a[u],a[v])) return;
		ansx[m+1]=a[u].id,ansy[m+1]=a[v].id;
		nxt.clear();
		for (node j:a) if (!j.check(x,y)) nxt.push_back(j);
		if (a.size()-nxt.size()<a.size()/(unsigned)(k-m)) continue;
		if (nxt.size()>max(1.0*(k-m-1),1.0*a.size()*(1-0.5/(k-m)))) continue;
		dfs(m+1,nxt);
	}
}
 
signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	srand(time(0));
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		tmp.id=i,
		tmp.A=read(),
		tmp.B=read(),
		tmp.C=read(),
		a.push_back(tmp);
	dfs(0,a);
	puts("NO");
	
	return 0;
}
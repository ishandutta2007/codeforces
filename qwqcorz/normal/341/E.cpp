#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e3+5;

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
int a[N];
vector<pair<int,int>>ans;
void move(int i,int j)
{
	assert(a[i]<=a[j]);
	a[j]-=a[i];
	a[i]+=a[i];
	ans.push_back(mk(i,j));
}
void sort(int &x,int &y,int &z)
{
	int p[3]={x,y,z};
	sort(p,p+3,[&](int u,int v){return a[u]<a[v];});
	x=p[0],y=p[1],z=p[2];
}
void solve(int &x,int &y,int z)
{
	sort(x,y,z);
	for (int t=a[y]/a[x];t;t/=2)
	if (t&1) move(x,y);
		else move(x,z);
	if (a[y]==0) swap(y,z);
	else solve(x,y,z);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),tot=0,x,y;
	for (int i=1;i<=n;i++) tot+=!!(a[i]=read());
	if (tot<2) return puts("-1"),0;
	for (int i=1;i<=n;i++) if (a[i]) {x=i;break;}
	for (int i=x+1;i<=n;i++) if (a[i]) {y=i;break;}
	for (int i=y+1;i<=n;i++) if (a[i]) solve(x,y,i);
	print(ans.size());
	for (auto i:ans) print(i.fi,' '),print(i.se);
	
	return 0;
}
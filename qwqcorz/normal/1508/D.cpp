#include<bits/stdc++.h>
#define mk make_pair
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
vector<pair<int,int>>ans;
struct node
{
	double ang;
	int x,y,id;
}a[N];
int fa[N],p[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void connect(int x,int y)
{
	swap(a[x].id,a[y].id);
	fa[find(x)]=find(y);
	ans.push_back(mk(x,y));
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),Min=0,cnt=0;
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].id=read();
	for (int i=1;i<=n;i++) if (i!=a[i].id&&(!Min||a[i].x<a[Min].x)) Min=i;
	if (Min==0) return puts("0"),0;
	for (int i=1;i<=n;i++) fa[i]=i,Min!=i&&a[i].id!=i?p[++cnt]=i:0;
	for (int i=1;i<=n;i++) fa[find(i)]=find(a[i].id);
	for (int i=1;i<=n;i++) a[i].ang=atan2(a[i].y-a[Min].y,a[i].x-a[Min].x);
	sort(p+1,p+cnt+1,[&](int x,int y){return a[x].ang<a[y].ang;}); p[++cnt]=Min;
	for (int i=2;i<=cnt;i++) if (find(p[i])!=find(p[i-1])) connect(p[i],p[i-1]);
	while (a[Min].id!=Min) connect(Min,a[Min].id);
	print(ans.size());
	for (auto i:ans) print(i.first,' '),print(i.second);
	
	return 0;
}
#include<bits/stdc++.h>
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
vector<pair<int,int>>ans;
int a[N],p[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return a[x]==a[y]?x<y:a[x]<a[y];});
	for (int i=1;i<=n;i++)
	for (int j=n;j>p[i];j--)
	if (a[p[i]]>a[j]) ans.push_back(make_pair(p[i],j));
	print(ans.size());
	for (auto i:ans) print(i.first,' '),print(i.second);
	
	return 0;
}
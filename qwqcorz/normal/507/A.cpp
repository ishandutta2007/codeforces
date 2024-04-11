#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int a[N],p[N];
void GreenDay()
{
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return a[x]<a[y];});
	vector<int>ans;
	for (int i=1;i<=n;i++) if (k>=a[p[i]]) k-=a[p[i]],ans.push_back(p[i]);
	print(ans.size());
	for (int i:ans) print(i,' ');
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
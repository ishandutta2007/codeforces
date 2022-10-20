#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=4e5+5;

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
int a[N],Max[N],cnt=0,sq[N],tot[N],p[N];
pair<int,int>t[N];
map<int,int>b;
vector<int>ans[N],fac[N];
bool cmp(int x,int y)
{
	return tot[x]!=tot[y]?tot[x]>tot[y]:a[x]<a[y];
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),tmp=0;
	for (int i=1;i<=n;i++) b[read()]++;
	for (auto i:b) t[++cnt]=mk(i.se,i.fi);
	sort(t+1,t+1+cnt);
	for (int i=1;i<=n;i++)
	for (int j=cnt;j>=1;j--)
	if (t[j].fi>=i) a[++tmp]=t[j].se,Max[tmp]=i;
			   else break;
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i)
	fac[j].push_back(i);
	for (int i=1;i<=n;i++) sq[i]=sqrt(i);
	int x=0,y=0;
	for (int i=n;i>=1;i--)
	if (Max[i]<=sq[i])
	{
		bool flag=0;
		for (int j:fac[i])
		if (Max[i]<=j&&j<=sq[i])
		{
			x=j;
			y=i/j;
			flag=1;
			break;
		}
		if (flag) break;
	}
	print(x*y);
	print(x,' ');
	print(y);
	tmp=0;
	b.clear();
	for (int i=1;i<=x*y;i++) b[a[i]]++;
	for (int i=1;i<=x*y;i++) p[i]=i,tot[i]=b[a[i]];
	sort(p+1,p+1+x*y,cmp);
	for (int i=0;i<x;i++) ans[i].resize(y);
	for (int j=0;j<y;j++)
	for (int i=0;i<x;i++) ans[i][(i+j)%y]=a[p[j*x+i+1]];
	for (int i=0;i<x;i++,puts(""))
	for (int j=0;j<y;j++) print(ans[i][j],' ');
	
	return 0;
}
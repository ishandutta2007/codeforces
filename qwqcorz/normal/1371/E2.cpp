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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
vector<int>b[N],ans;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),p=read(),l,r=0;
	for (int i=1;i<=n;i++) r=max(r,a[i]=read());
	sort(a+1,a+1+n);
	l=max(r-n+1,1);
	for (int i=l,j=0;i<=r+n;i++)
	{
		while (j<n&&a[j+1]<=i) j++;
		b[((i-j)%p+p)%p].push_back(i);
	}
	for (int i=l;i<=r;i++)
	{
		int x=i%p;
		auto pos=lower_bound(b[x].begin(),b[x].end(),i);
		if (pos==b[x].end()||*pos>=i+n) ans.push_back(i);
	}
	print(ans.size());
	for (int i:ans) print(i,' ');
	puts("");
	
	return 0;
}
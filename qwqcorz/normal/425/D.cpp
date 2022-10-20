#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=sqrt(N);

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
vector<int>a[N],id;
unordered_map<int,int>t[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[x].push_back(y);
		t[x][y]=1;
	}
	for (int i=0;i<=1e5;i++) sort(a[i].begin(),a[i].end());
	for (int i=0;i<=1e5;i++)
	if ((int)a[i].size()<=B)
	for (int j=0;j<(int)a[i].size();j++)
	for (int k=j+1;k<(int)a[i].size();k++)
	{
		int x=a[i][k]-a[i][j];
		if (i>=x&&(int)a[i-x].size()>B) ans+=t[i-x].count(a[i][j])&&t[i-x].count(a[i][k]);
		if (i+x<=1e5) ans+=t[i+x].count(a[i][j])&&t[i+x].count(a[i][k]);
	}
	else
	{
		for (int j=0;j<(int)a[i].size();j++)
		for (int k:id)
		if (t[k].count(a[i][j]))
		{
			int x=i-k;
			ans+=t[k].count(a[i][j]+x)&&t[k].count(a[i][j]+x);
		}
		id.push_back(i);
	}
	print(ans);
	
	return 0;
}
#include<bits/stdc++.h>
#define piir pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2.5e5+5;

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
void output(vector<int>&ans)
{
	puts("Yes");
	for (int i:ans) print(i,' ');
	puts("");
	exit(0);
}
int n,m;
vector<int>a[N],ans;
piir findmax(vector<int>&b)
{
	piir ret(0,0);
	for (int i=0;i<n;i++)
	{
		int tot=0;
		for (int j=0;j<m;j++) tot+=b[j]!=a[i][j];
		ret=max(ret,mk(tot,i));
	}
	return ret;
}
vector<int>diff(vector<int>&a,vector<int>&b)
{
	vector<int>ret(0);
	for (int i=0;i<m;i++) if (a[i]!=b[i]) ret.push_back(i);
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) a[i].push_back(read());
	ans=a[0];
	piir tmp=findmax(ans);
	if (tmp.fi<=2) output(ans);
	if (tmp.fi>4) return puts("No")*0;
	int id=tmp.se;
	if (tmp.fi==4)
	{
		vector<int>pos=diff(ans,a[id]);
		for (int i=0;i<(1<<4);i++)
		if (__builtin_popcount(i)==2)
		{
			for (int j=0;j<4;j++)
			if ((i>>j)&1) ans[pos[j]]=a[0][pos[j]];
					 else ans[pos[j]]=a[id][pos[j]];
			if (findmax(ans).fi<=2) output(ans);
		}
	}
	else
	{
		vector<int>pos=diff(ans,a[id]);
		for (int k=0;k<3;k++)
		for (int i=0;i<(1<<3);i++)
		if (__builtin_popcount(i)==2)
		{
			for (int j=0;j<3;j++)
			if ((i>>j)&1) ans[pos[j]]=a[0][pos[j]];
					 else ans[pos[j]]=a[id][pos[j]];
			piir tmp=findmax(ans);
			if (tmp.fi<=2) output(ans);
			else if (tmp.fi==3)
			{
				ans[pos[k]]=a[tmp.se][pos[k]];
				if (findmax(ans).fi<=2) output(ans);
			}
		}
	}
	puts("No");
	
	return 0;
}
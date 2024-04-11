#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;

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
vector<pair<int,int> >ans;
vector<int>a[20];
void perform(int x,int y) {ans.push_back(mk(x,y));}
void merge(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	for (int i=l,j=mid+1;i<=mid;i++,j++) perform(i,j);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=0,cnt=0;
	for (int k=1<<(int)log2(n);k;k>>=1)
	if (m+k<=n)
	{
		cnt++;
		merge(m+1,m+k);
		for (int i=m+1;i<=m+k;i++) a[cnt].push_back(i);
		m+=k;
	}
	while (cnt>2)
	{
		while (a[cnt].size()<a[cnt-1].size())
		{
			int tmp=a[cnt].size();
			while (tmp--) perform(a[1].back(),a[cnt][tmp]),a[cnt].push_back(a[1].back()),a[1].pop_back();
		}
		for (int i=0;i<(int)a[cnt].size();i++) perform(a[cnt][i],a[cnt-1][i]);
		for (int i:a[cnt]) a[cnt-1].push_back(i);
		cnt--;
	}
	print(ans.size());
	for (pair<int,int>i:ans) print(i.fi,' '),print(i.se);
	
	return 0;
}
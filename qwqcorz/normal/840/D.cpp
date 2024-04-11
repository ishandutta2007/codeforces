#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
vector<int>p[N];
int a[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	int n,num[5],HP[5];
	node operator +(const node &a)
	{
		node ans=a;
		for (int i=1;i<=n;i++)
		{
			bool tag=0;
			for (int j=1;j<=ans.n;j++)
			if (ans.num[j]==num[i])
			{
				ans.HP[j]+=HP[i];
				tag=1;
				break;
			}
			if (tag) continue;
			if (ans.n<4)
			{
				ans.num[++ans.n]=num[i];
				ans.HP[ans.n]=HP[i];
				continue;
			}
			int k=1;
			for (int j=2;j<=ans.n;j++) if (ans.HP[j]<ans.HP[k]) k=j;
			if (ans.HP[k]>HP[i]) for (int j=1;j<=ans.n;j++) ans.HP[j]-=HP[i];
			else
			{
				int dec=ans.HP[k];
				ans.num[k]=num[i];
				ans.HP[k]=HP[i];
				for (int j=1;j<=ans.n;j++) ans.HP[j]-=dec;
			}
		}
		return ans;
	}
}t[N*4];
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=(node){1,{0,a[l],0,0,0},{0,1,0,0,0}});
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int ql,int qr)
{
	if (ql<=l&&r<=qr) return t[w];
	if (qr<=mid) return query(ls,l,mid,ql,qr);
	if (ql>mid) return query(rs,mid+1,r,ql,qr);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
#undef mid
#undef rs
#undef ls

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) p[a[i]=read()].push_back(i);
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read(),k=read();
		node get=query(1,1,n,l,r);
		vector<int>ans;
		for (int j=1;j<=get.n;j++)
		{
			int x=get.num[j];
			int L=lower_bound(p[x].begin(),p[x].end(),l)-p[x].begin();
			int R=upper_bound(p[x].begin(),p[x].end(),r)-p[x].begin();
			if (R-L>(r-l+1)/k) ans.push_back(x);
		}
		if (ans.empty()) puts("-1");
					else print(*min_element(ans.begin(),ans.end()));
	}
	
	return 0;
}
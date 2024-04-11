#include<bits/stdc++.h>
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
int ask(int x,int l,int r)
{
	printf("? %d %d\n",1,r-l+1);
	print(x);
	for (int i=l;i<=r;i++) print(i," \n"[i==r]);
	fflush(stdout);
	return read();
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		vector<int>ans(0);
		int n=read(),pos=0;
		for (int i=2;i<=n;i++)
		if (ask(i,1,i-1))
		{
			pos=i;
			break;
		}
		for (int i=pos+1;i<=n;i++) if (!ask(pos,i,i)) ans.push_back(i);
		int l=1,r=pos-1;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (ask(pos,1,mid)) r=mid-1;
						   else l=mid+1;
		}
		for (int i=1;i<pos;i++) if (i!=l) ans.push_back(i);
		printf("! %d",(int)ans.size());
		for (int i:ans) printf(" %d",i);
		cout<<endl;
	}
	
	return 0;
}
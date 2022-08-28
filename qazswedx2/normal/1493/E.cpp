#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
struct bint
{
	char s[1000005];
	bool operator<(const bint x) const
	{
		return strcmp(s+1,x.s+1)<0;
	}
	bool operator<=(const bint x) const
	{
		return strcmp(s+1,x.s+1)<=0;
	}
	void add()
	{
		int id=-1;
		for(int i=n;i>=1;i--)
			if(s[i]=='0')
			{
				id=i;
				break;
			}
		s[id]='1';
		for(int i=id+1;i<=n;i++)
			s[i]='0';
	}
	void sub()
	{
		int id=-1;
		for(int i=n;i>=1;i--)
			if(s[i]=='1')
			{
				id=i;
				break;
			}
		s[id]='0';
		for(int i=id+1;i<=n;i++)
			s[i]='1';
	}
/*	bint operator^(const bint x) const
	{
		bint y;
		for(int i=1;i<=n;i++)
			if(s[i]!=x.s[i]) y.s[i]='1';
			else y.s[i]='0';
		return y;
	}*/
}l,r;
bint q,z;
int main()
{
	scanf("%d%s%s",&n,l.s+1,r.s+1);
	for(int i=1;i<=n;i++)
		z.s[i]='0';
	int fl=0;
	for(int i=1;i<=n;i++)
		if(l.s[i]=='1')
			fl=1;
	if(fl) l.sub();
	q.s[1]='1';
	for(int i=2;i<=n;i++)
		q.s[i]='0';
//	printf("q=%s,l=%s,r=%s\n",q.s+1,l.s+1,r.s+1);
	if(n>=3&&l<=q&&q<=r)
	{
		q.sub();
		q.sub();
		if(l<=q&&q<=r)
		{
	//		printf("---\n");
			for(int i=1;i<=n;i++)
				printf("1");
			return 0;
		}
	}
	int fl0=0,fl1=0,fl2=0;
	bint mx;
	for(int i=1;i<=n;i++)
		mx.s[i]='0';
	r.s[0]='0';
	for(int i=1;i<=4;i++)
	{
		if(r.s[n]=='0'&&!fl2)
		{
			fl2=1;
			mx=r;
			if(r.s[n-1]=='1')
			{
				mx.add();
			}
		}
		if(r<=z&&z<=r) fl0=1;
		if(r.s[n-1]=='0'&&r.s[n]=='1')
			fl1=1;
		if(r.s[n-1]=='1'&&r.s[n]=='1')
			fl0=1;
		if(r<=l) break;
		r.sub();
	}
	bint ans0,ans1;
	for(int i=1;i<=n;i++)
		ans0.s[i]=ans1.s[i]='0';
	if(fl0) ans0=mx;
	if(fl1)
	{
		ans1=mx;
		if(ans1.s[n]=='0') ans1.s[n]='1';
		else ans1.s[n]='0';
	}
	if(ans0<ans1) ans0=ans1;
	printf("%s",ans0.s+1);
	return 0;
}
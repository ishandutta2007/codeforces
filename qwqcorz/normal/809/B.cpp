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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
string s;
inline int Q(int x,int y)
{
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	cin>>s;
	return s=="TAK";
}
inline void answer(int x,int y)
{
	printf("2 %d %d\n",x,y);
	fflush(stdout);
	exit(0);
}
inline int get(int l,int r)
{
	while (l<r)
	{
		int mid=(l+r)/2;
		if (Q(mid,mid+1)) r=mid;
					 else l=mid+1;
	}
	return l;
}

signed main()
{
	int n=read(),k=read();(void)k;
	int x=get(1,n);
	if (x<n)
	{
		int tmp=get(x+1,n);
		if (x!=tmp&&Q(x,tmp)&&Q(tmp,x)) answer(x,tmp);
	}
	if (x>1)
	{
		int tmp=get(1,x-1);
		if (x!=tmp&&Q(x,tmp)&&Q(tmp,x)) answer(x,tmp);
	}
	
	return 0;
}
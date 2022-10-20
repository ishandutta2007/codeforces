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
void output(int x,int y)
{
	print(x,' ');
	print(y);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	if (n%4>=2) puts("NO");
	else
	{
		puts("YES");
		for (int i=0;i<n/4;i++)
		{
			int x=i*4;
			output(x+1,x+2);
			output(x+3,x+4);
			output(x+1,x+4);
			output(x+2,x+3);
			if (n&1) output(x+1,n);
			if (n&1) output(x+2,n);
			output(x+1,x+3);
			output(x+2,x+4);
			if (n&1) output(x+4,n);
			if (n&1) output(x+3,n);
		}
		for (int i=0;i<n/4;i++)
		for (int j=i+1;j<n/4;j++)
		{
			/*
			(1,1) (2,2) (1,2) (2,1)
			(1,3) (2,4) (1,4) (2,3)
			(3,1) (4,2) (3,2) (4,1)
			(3,3) (4,4) (3,4) (4,3)
			*/
			int x=i*4,y=j*4;
			output(x+1,y+1);
			output(x+2,y+2);
			output(x+1,y+2);
			output(x+2,y+1);
			output(x+1,y+3);
			output(x+2,y+4);
			output(x+1,y+4);
			output(x+2,y+3);
			output(x+3,y+1);
			output(x+4,y+2);
			output(x+3,y+2);
			output(x+4,y+1);
			output(x+3,y+3);
			output(x+4,y+4);
			output(x+3,y+4);
			output(x+4,y+3);
		}
	}

	return 0;
}
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
vector<int>ans1,ans2;

signed main()
{
	int n=read(),m=read();m=m;
	int x=5,y=4,s1=5,s2=5;
	while (s1<n||s2<n)
	{
		s1+=x;
		s2+=y;
		ans1.push_back(x);
		ans2.push_back(y);
		swap(x,y);
	}
	ans1.push_back(5);
	ans2.push_back(5);
	for (int i:ans1) putchar(i+'0');puts("");
	for (int i:ans2) putchar(i+'0');puts("");
	
	return 0;
}
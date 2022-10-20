#include<bits/stdc++.h>
#define iter map<int,string>::iterator
#define int long long
#define x first
#define y second
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
map<int,string>num;

signed main()
{
	num.clear();
	int n=read();
	for (int i=2;i*i<=n;i++)
	for (int j=2,k=i*i;k<=n;j++,k*=i)
	{
		string now=to_string(i)+'^'+to_string(j);
		if (!num.count(k)) num[k]=now;
		if (num[k].length()>now.length()) num[k]=now;
	}
	string ans=to_string(n);
	for (iter i=num.begin();i!=num.end();i++)
	if (i->y.length()>to_string(i->x).length())
	i->y=to_string(i->x);
	for (iter i=num.begin();i!=num.end();i++)
	{
		string now=i->y;
		int a=i->x,b=n/a,c=n-a*b;
		if (!num.count(b)) num[b]=to_string(b);
		if (!num.count(c)) num[c]=to_string(c);
		if (b>1) now+='*'+num[b];
		if (c) now+='+'+num[c];
		if (ans.length()>now.length()) ans=now;
	}
	cout<<ans;

	return 0;
}
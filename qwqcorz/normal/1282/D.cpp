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
int Q(string a)
{
	cout<<a<<endl;
	int ret=read();
	if (!ret) exit(0);
	return ret;
}
string s;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int a=Q("a"),b=0;
	if (a>=300) Q(string(a,'b'));
	int aaa=Q(string(a+1,'a'));
	if (aaa==a+1) Q(string(a,'b'));
	a++;
	for (int i=1;i<=a;i++) s+='a';
	for (int i=0;i<a-1;i++)
	{
		s[i]='b';
		if (Q(s)==aaa-b-1) b++;
					  else s[i]='a';
		if (aaa==b) break;
	}
	if (aaa!=b) s[a-1]='b';
	Q(s);
	
	return 0;
}
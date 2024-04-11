#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
inline int Q(string q,int x,int y)
{
	cout<<q<<' '<<x<<' '<<y<<endl;
	return read();
}
int a[N],Xor[N],t[N],n;
void get()
{
	for (int i=1;i<=n;i++)
	if (t[Xor[i]])
	{
		a[i]=Q("OR",i,t[Xor[i]]);
		a[1]=a[i]^Xor[i];
		return;
	}
	else t[Xor[i]]=i;
	for (int i=1;i<=n;i++)
	if (Xor[i]==1) a[1]^=Q("OR",1,i)&~1;
	else if (Xor[i]==2) a[1]^=Q("OR",1,i)&1;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read();
	for (int i=2;i<=n;i++) Xor[i]=Q("XOR",1,i);
	get();
	for (int i=2;i<=n;i++) a[i]=a[1]^Xor[i];
	putchar('!');
	putchar(' ');
	for (int i=1;i<=n;i++) print(a[i],' ');
	fflush(stdout);
	
	return 0;
}
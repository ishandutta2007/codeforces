#include<bits/stdc++.h>
#define int long long
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct oper
{
	int x;
	char o;
	int y;
};
vector<oper>opt;
int getlen(int x){int ret=0;while (x) x>>=1,ret++;return ret;}
int Add(int x,int y){opt.push_back((oper){x,'+',y});return x+y;}
int Xor(int x,int y){opt.push_back((oper){x,'^',y});return x^y;}
int move(int x,int k)
{
	for (int i=1;i<=k;i++) x=Add(x,x);
	return x;
}
void solve(int &x)
{
	int len=getlen(x);
	int y=move(x,len-1);
	int z=Xor(x,y);
	int r=Add(y,z);
	int b=Xor(Xor(r,x),Add(y,y));
	while (y>=b)
	{
		if (y&b) y=Xor(y,b);
		b=Add(b,b);
	}
	x=Xor(x,y);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	while (n>1) solve(n);
	print(opt.size());
	for (auto i:opt) printf("%lld %c %lld\n",i.x,i.o,i.y);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
double rnd(){return 1.0*(1LLu*rand()*RAND_MAX+rand())/(1LLu*RAND_MAX*RAND_MAX);}
char a[N];
int t[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	while (m--)
	{
		scanf("%s",a+1);
		double p[2]={0,0};
		for (int i=1;i<=n;i++) p[a[i]-'0']+=pow(0.75,t[i]);
		cout<<(rnd()<=p[1]/(p[1]+p[0]))<<endl;
		int x=read();
		for (int i=1;i<=n;i++) t[i]+=a[i]-'0'!=x;
	}
	
	return 0;
}
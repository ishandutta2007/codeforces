#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
inline int read()
{
	int x=0,ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int n,m,p,a[1000005],b[1000005];
int main()
{
	n=read(),m=read(),p=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	for(int i=0;i<m;i++)
		b[i]=read();
	int nw=0;
	for(int i=0;i<=n+m-2;i++)
	{
		if(a[nw]%p!=0&&b[i-nw]%p!=0)
		{
			printf("%d\n",i);
			return 0;
		}
		if(a[nw]%p==0) nw++;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

int n,m,T,k; 
int a[10001];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	n=read(),k=read();
	if (n%2==0) 
	{
		k%=n;
		if (k==0) k=n;
		printf("%d\n",k);
		return;
	}
	int u=(k-1)/n+1;
	int tmp=k-(u-1)*n;
	int v=n/2;
	int t=u%v;
	if (t==0) t=v;
	t=t*2-1;
	int x=(n+t)/2;
	int y=x-t+1,j=(n-1)/2;
	int ans;
	if (tmp<y) 
	{
		ans=tmp+t-1;
	} 
	else if (tmp<y+j) ans=tmp+t;
	else ans=tmp+t+1;
	ans%=n;
	if (ans==0) ans=n;
	printf("%d\n",ans);
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}
// 5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
// 1 2 4 5 2 3 5 1 3 4 1 2 4 5 2

// 1 3 5 1 3 5

// n x   x-t
// t x+1 x+1+t-n
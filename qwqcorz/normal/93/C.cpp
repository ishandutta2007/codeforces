#include<bits/stdc++.h>
using namespace std;
const int N=10;
const string name_list[7]={"ezx","eax","ebx","ecx","edx","eex","efx"};

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N]={0,1},L[N],R[N],K[N],n;
void Print(int n)
{
	print(n);
	for (int i=1;i<=n;i++)
	printf("lea %s, [%s + %d*%s]\n",
	name_list[i+1].c_str(),
	name_list[L[i]].c_str(),
	K[i],
	name_list[R[i]].c_str()
	);
}
void dfs(int now,int up)
{
	if (now==up)
	{
		if (a[now]==n)
		{
			Print(now-1);
			exit(0);
		}
		return;
	}
	for (int i=0;i<=now;i++)
	for (int j=i+1;j<=now;j++)
	for (int k=1;k<=8;k*=2)
	{
		L[now]=i;
		R[now]=j;
		K[now]=k;
		a[now+1]=a[i]+k*a[j];
		dfs(now+1,up);
	}
	for (int i=0;i<=now;i++)
	for (int j=0;j<=i;j++)
	for (int k=2;k<=8;k*=2)
	{
		L[now]=i;
		R[now]=j;
		K[now]=k;
		a[now+1]=a[i]+k*a[j];
		dfs(now+1,up);
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read();
	if (n==1) return puts("0"),0;
	for (int i=2;;i++) dfs(1,i);

	return 0;
}
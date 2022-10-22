//by Little09 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=100005;
int a[N];
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
void ask(int x)
{
	if (a[x]!=-1) return;
	cout << "? " << x << endl;
	fflush(stdout);
	int y=read();
	a[x]=y;
}
void work()
{
	n=read();
	memset(a,-1,sizeof(a));
	a[0]=N,a[n+1]=N;
	//fflush(stdout);
	int l=1,r=n;
	ask(1),ask(2),ask(n),ask(n-1);
	if (a[1]<a[2]) 
	{
		cout << "! " << 1 << endl;
		fflush(stdout);
		return;
	}
	if (a[n]<a[n-1]) 
	{
		cout << "! " << n << endl;
		fflush(stdout);
		return;
	}
	while (r-l+1>3)
	{
		int mid1=(l*2+r)/3,mid2=(l+r*2)/3;
		ask(mid1),ask(mid2);
		if (a[mid1]>a[mid2]) l=mid1+1;
		else r=mid2-1;
	}
	for (int i=l;i<=r;i++)
	{
		ask(i);
	}
	for (int i=l;i<=r;i++)
	{
		if (a[i]<a[i-1]&&a[i]<a[i+1]) 
		{
			cout << "! " << i << endl;
			fflush(stdout);
			return;
		}
	}
}
int main()
{
	work(); 
	return 0;
}
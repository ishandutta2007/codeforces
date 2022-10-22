#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

int n; 


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

int a[300][300];

void work(int &x,int &y,int k)
{
	printf("%d %d %d\n",k,x,y);
	fflush(stdout);
	y+=2;
	if (y>n)
	{
		if (y%2==1) y=2;
		else y=1;
		x++;
	}
}

int main()
{
	n=read();
	int ans1=(n*n+1)/2,ans2=n*n-ans1,res1=0,res2=0;
	int x1=1,y1=1,x2=1,y2=2;
	for (int i=1;i<=n*n;i++)
	{
		int x=read();
		if (x!=2&&res2!=ans2)
		{
			work(x2,y2,2);
			res2++;
		}
		else if (x!=1&&res1!=ans1)
		{
			work(x1,y1,1);
			res1++;
		} 
		else
		{
			if (res2==ans2) work(x1,y1,3);
			else work(x2,y2,3);
		}
	}
	return 0;
}
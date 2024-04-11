#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
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
int u[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int h,int m,int x,int y)
{
	int a=y%10;
	int b=u[a];
	if (b==-1) return 0;
	int x1=b*10;
	a=y/10,b=u[a];
	if (b==-1) return 0;
	x1+=b;
	if (x1>=h) return 0;
	a=x%10;
	b=u[a];
	if (b==-1) return 0;
	x1=b*10;
	a=x/10,b=u[a];
	if (b==-1) return 0;
	x1+=b;
	if (x1>=m) return 0;
	return 1;
}
void print(int x,int y)
{
	if (x<10) cout << 0;
	cout << x;
	cout << ":";
	if (y<10) cout << 0;
	cout << y;
	cout << endl;
}
void work()
{
	int h=read(),m=read();
	int x,y;
	char t;
	cin >> x >> t >> y;
	while (1)
	{
		if (check(h,m,x,y))
		{
			print(x,y);
			return;
		}
		y++;
		if (y==m) 
		{
			y=0,x++;
		}
		if (x==h)
		{
			x=0;
		}
		
	}
	return;
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
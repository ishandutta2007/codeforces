// By: Little09
// Problem: B. Range and Partition
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int x,y,sum;
int b[N],c[N];
bool check()
{
	if (x>y) return 0;
	if (sum>=m) return 1;
	return 0;
}
void print(int l,int r)
{
	for (int i=1;i<=n;i++) 
	{
		if (a[i]>=l&&a[i]<=r) c[i]=1;
		else c[i]=-1;
	}
	int res=0,tot=0,last=1;
	for (int i=1;i<=n;i++)
	{
		res+=c[i];
		if (res==1&&tot!=m-1)
		{
			printf("%d %d\n",last,i);
			last=i+1;
			res=0;
			tot++;
		}
	}
	printf("%d %d\n",last,n);
}
void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) b[i]=0;
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]++;
	x=1,y=0,sum=-n;
	int ans=n*2,ansx=-1;
	while (1)
	{
		while (check()==0&&y<=n) y++,sum+=2*b[y];
		if (y==n+1) break;
		while (check()==1&&x<=y) 
		{
			if (y-x+1<ans)
			{
				ans=y-x+1;
				ansx=x;
			}	
			sum-=2*b[x];
			x++;
		}
	}
	printf("%d %d\n",ansx,ansx+ans-1);
	print(ansx,ansx+ans-1);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
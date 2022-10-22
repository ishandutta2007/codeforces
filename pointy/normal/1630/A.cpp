// By: Little09
// Problem: A. And Matching
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
bool used[N];
void work()
{
	n=read(),m=read();
	if (n==4&&m==3)
	{
		cout << -1 << endl;
		return;
	}
	if (m!=n-1)
	{
		for (int i=0;i<n;i++) used[i]=0;
		printf("%d %d\n",n-1,m);
		used[n-1]=1,used[m]=1;
		for (int i=n-1;i>=0;i--)
		{
			if (used[i]==1) continue;
			int j=(i^(n-1));
			if (used[j]==0)
			{
				printf("%d %d\n",i,j);
				used[i]=1,used[j]=1;
			}
			else
			{
				printf("%d %d\n",i,0);
				used[i]=1,used[0]=1;
			}
		}
	}
	else
	{
		for (int i=0;i<n;i++) used[i]=0;
		printf("%d %d\n",n-1,n-2);
		printf("%d %d\n",1,3);
		used[n-1]=1,used[n-2]=1;
		used[1]=1,used[3]=1;
		for (int i=n-1;i>=0;i--)
		{
			if (used[i]==1) continue;
			int j=(i^(n-1));
			if (j==3) j=2;
			else if (j==2) j=0;
			used[i]=1,used[j]=1;
			printf("%d %d\n",i,j);
		}
	}
	//cout << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
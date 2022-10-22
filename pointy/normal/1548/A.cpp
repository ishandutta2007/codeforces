// By: Little09
// Problem: A. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/A
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

const int N=200005;
int n,m,T; 
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
set<int>q[N];
int ans;
void work()
{
	n=read(),m=read();
	ans=0;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (x>y) swap(x,y);
		if (q[x].empty()) ans++;
		q[x].insert(y);
	}
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int tp=read();
		if (tp==1)
		{
			int x=read(),y=read();
			if (x>y) swap(x,y);
			if (q[x].empty()) ans++;
			q[x].insert(y);
		}
		else if (tp==2)
		{
			int x=read(),y=read();
			if (x>y) swap(x,y);
			q[x].erase(y);
			if (q[x].empty()) ans--;
		}
		else printf("%d\n",n-ans);
	}
	return;
}

int main()
{
	int tp=1;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}
// By: Little09
// Problem: C. Omkar and Determination
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/C
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

const int N=1000005;
int n,m,T,q; 
vector<char>a[N];
int s[N*2];
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

void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) 
	{
		a[i].push_back(' ');
		for (int j=1;j<=m;j++)
		{
			char x=readchar();
			a[i].push_back(x);
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<m;j++)
		{
			int x=i-1,y=j+1;
			if (a[x][y]=='X'&&a[i][j]=='X')
			{
				s[j*2+1]=1;
			}
		}
	}
	for (int i=1;i<=m*2;i++) s[i]=s[i-1]+s[i];
	q=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		int x=s[r*2]-s[l*2];
		if (x==0) printYES;
		else printNO;
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
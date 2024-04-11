// By: Little09
// Problem: D. Diane
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/D
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
void ww(char x,char y)
{
	for (char i=x;i<=y;i+=1) cout << i;
}
void work()
{
	n=read();
	if (n<=15)
	{
		ww('a','a'+n-1);
		cout << endl;
		return;
	}
	if (n%2==1)
	{
		cout << "a";
		int ans=(n-2)/2;
		for (int i=1;i<=ans;i++) cout << "b";
		cout << "c";
		for (int i=1;i<=ans+1;i++) cout << "b";
	}
	else 
	{
		cout << "da";
		int ans=(n-3)/2;
		for (int i=1;i<=ans;i++) cout << "b";
		cout << "c";
		for (int i=1;i<=ans+1;i++) cout << "b";
	}
	cout << endl;
	return;
}

int main()
{
	int tp=0;
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
// By: Little09
// Problem: A. Polycarp and Coins
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
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
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x=read(),y=x/3;
		if (x%3==0) printf("%d %d\n",y,y);
		else if (x%3==1) printf("%d %d\n",y+1,y);
		else printf("%d %d\n",y,y+1);
	}
	return 0;
}
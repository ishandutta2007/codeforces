// Author: Little09
// Problem: CF1305B Kuroni and Simple Strings
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1305B
// Memory Limit: 250 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N];
bool p[N],ans;

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
	cin >> (a+1);
	n=strlen(a+1);
	int l=1,r=n;
	while (l<=r)
	{
		while (l<=r&&a[l]==')') l++;
		while (l<=r&&a[r]=='(') r--;
		if (l<=r)
		{
			p[l]=1,p[r]=1;
			ans=1;
			m+=2;
			l++,r--;
		}
	}
	if (ans==0)
	{
		cout << 0;
		return 0;
	}
	cout << ans << endl << m << endl;
	for (int i=1;i<=n;i++)
	{
		if (p[i]) cout << i << " ";
	}
	return 0;
}
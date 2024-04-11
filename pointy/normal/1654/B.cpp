// By: Little09
// Problem: B. Prefix Removals
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N];
int b[30];

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
	cin >> (a+1);
	n=strlen(a+1);
	mem(b);
	for (int i=1;i<=n;i++) b[a[i]-'a']++;
	for (int i=1;i<=n;i++) 
	{
		if (b[a[i]-'a']==1)
		{
			for (int j=i;j<=n;j++) cout << a[j];
			cout << endl;
			return;
		}
		b[a[i]-'a']--;
	}
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
// By: Little09
// Problem: C. Alice and the Cake
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/C
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
map<ll,ll>s;
bool dfs(ll x)
{
	if (s[x]>=1) 
	{
		s[x]--;
		return 1;
	}
	if (x==1)
	{
		return 0;
	}
	ll l=x/2,r=x-l;
	bool flag=dfs(l)&&dfs(r);
	return flag;
}
void work()
{
	n=read();
	ll sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	for (int i=1;i<=n;i++) s[a[i]]++;
	bool flag=dfs(sum);
	for (int i=1;i<=n;i++) s[a[i]]=0;
	if (flag) printYES;
	else printNO;
	return;
}



int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
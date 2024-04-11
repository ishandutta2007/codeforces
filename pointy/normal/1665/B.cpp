// By: Little09
// Problem: B. Array Cloning Technique
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.ml/contest/1665/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
map<int,int>q;

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
	n=read(),m=0;
	int ans=0;
	for (int i=1;i<=n;i++) a[i]=read(),q[a[i]]++,m=max(m,q[a[i]]);
	while (m<n)
	{
		ans++;
		if (m*2<=n)
		{
			ans+=m;
			m+=m;
		}
		else
		{
			ans+=n-m;
			break;
		}
	}
	cout << ans << endl;
	for (int i=1;i<=n;i++) q[a[i]]=0;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
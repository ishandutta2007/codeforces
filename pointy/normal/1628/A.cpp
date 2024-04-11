// By: Little09
// Problem: A. Meximum Array
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/A
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
int a[N],b[N],len,c[N],d[N];

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
int res;
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
int find(int x,int y)
{
	int tot=0;
	for (int i=x;i<=n;i++)
	{
		if (a[i]<y&&c[a[i]]==0) tot++;
		c[a[i]]++;
		d[a[i]]--;
		if (d[a[i]]==0) res=min(res,a[i]);
		if (tot==y) return i;
	}
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	len=0;
	res=n;
	for (int i=0;i<=n;i++) c[i]=0;
	for (int i=0;i<=n;i++) d[i]=0;
	for (int i=1;i<=n;i++) d[a[i]]++;
	for (int i=0;i<=n;i++) if (d[i]==0) res=min(res,i);
	int l=1,r;
	while (1)
	{
		b[++len]=res;
		r=find(l,res);
		for (int j=l;j<=r;j++) c[a[j]]--;
		l=r+1;
		if (l>n) break;
	}
	printf("%d\n",len);
	for (int i=1;i<=len;i++) printf("%d ",b[i]);
	printf("\n");
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
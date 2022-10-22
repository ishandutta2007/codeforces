// Author: Little09
// Problem: CF1698F Equal Reversal
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1698F
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

const int N=505;
int n,m; 
int a[N],b[N];
int used[N][N],cnt,ans[N*N][2];

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
void reverse(int l,int r)
{
	++cnt;
	ans[cnt][0]=l,ans[cnt][1]=r;
	int len=(r-l+1)/2;
	for (int i=l;i<l+len;i++) swap(a[i],a[l+r-i]);
}
int vis[N];
void dd(int l,int r)
{
	if (r-l+1<=2) return;
	if (a[l+1]==b[l+1])
	{
		dd(l+1,r);
		return;
	}
	while (1)
	{
		for (int i=l+1;i<r;i++)
		{
			if (a[i+1]==b[l]&&a[i]==b[l+1])
			{
				reverse(l,i+1);
				dd(l+1,r);
				return;
			}
		}
		int tot=-1;
		for (int i=l+1;i<r;i++)
		{
			if (a[i]==b[l]&&a[i+1]==b[l+1])
			{
				tot=i;
				break;
			}
		}
		mem(vis);
		for (int i=l;i<=tot;i++) vis[a[i]]=i;
		for (int i=tot+1;i<=r;i++)
		{
			if (vis[a[i]]!=0)
			{
				reverse(vis[a[i]],i);
				break;
			}
		}	
	}
	
	
}
void work()
{
	n=read(),cnt=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	if (a[1]!=b[1]||a[n]!=b[n])
	{
		printNO;
		return;
	}
	mem(used);
	for (int i=1;i<n;i++) used[a[i]][a[i+1]]++,used[a[i+1]][a[i]]++;
	for (int i=1;i<n;i++)
	{
		if (used[b[i]][b[i+1]]<=0||used[b[i+1]][b[i]]<=0) 
		{
			printNO;
			return;
		}
		used[b[i]][b[i+1]]--;
		used[b[i+1]][b[i]]--;
	}
	dd(1,n);
	printYES;
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
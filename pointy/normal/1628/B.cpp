// By: Little09
// Problem: B. Peculiar Movie Preferences
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/B
// Memory Limit: 512 MB
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
int n,m,ans; 
char a[N][4];
int b[N],c[N];

bool checkb(int x,int y)
{
	if (b[x*26+y]) return 1;
	for (int i=0;i<26;i++) if (c[y+x*26+i*26*26]) return 1;
	return 0;
}

bool checkc(int x,int y,int z)
{
	if (c[x*26*26+y*26+z]) return 1;
	if (b[y*26+z]) return 1;
	return 0;
}

inline void addb(int x,int y)
{
	b[x+y*26]++;
}
inline void delb(int x,int y)
{
	b[x+y*26]--;
}
inline void addc(int x,int y,int z)
{
	c[x+y*26+z*26*26]++;
}
inline void delc(int x,int y,int z)
{
	c[x+y*26+z*26*26]--;
}

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
	n=read();
	for (int i=1;i<=n;i++) cin >> a[i];
	ans=0;
	for (int i=1;i<=n;i++)
	{
		int len=strlen(a[i]);
		if (len==1)
		{
			ans=1;
		}
		else if (len==2)
		{
			if (checkb(a[i][0]-'a',a[i][1]-'a')) ans=1;
			addb(a[i][0]-'a',a[i][1]-'a');
			if (a[i][0]==a[i][1]) ans=1;
		}
		else if (len==3)
		{
			if (checkc(a[i][0]-'a',a[i][1]-'a',a[i][2]-'a')) ans=1;
			addc(a[i][0]-'a',a[i][1]-'a',a[i][2]-'a');
			if (a[i][0]==a[i][2]) ans=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int len=strlen(a[i]);
		if (len==1);
		else if (len==2)
		{
			delb(a[i][0]-'a',a[i][1]-'a');
		}
		else if (len==3)
		{
			delc(a[i][0]-'a',a[i][1]-'a',a[i][2]-'a');
		}
	}
	if (ans==1) printYES;
	else printNO;
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
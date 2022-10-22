// By: Little09
// Problem: A. Windblume Ode
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/A
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
const int MAXN=N-5;
int mu[N],phi[N];
int p[N],v[N],cnt;
void init() 
{
    v[1]=mu[1]=phi[1]=1;
    cnt=0;
    for (int i=2;i<=MAXN;++i) 
	{
        if (!v[i]) p[++cnt]=i,mu[i]=-1,phi[i]=i-1;
        for (int j=1;j<=cnt&&i*p[j]<=MAXN;++j) 
		{
            v[i*p[j]]=1;
            if (i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
            else 
			{ 
				mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j]; 
				break; 
			}
        }
    }
    for (int i=1;i<=MAXN;++i) mu[i]+=mu[i-1],phi[i]+=phi[i-1];
}

void work()
{
	n=read();
	int sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	if (v[sum]==1)
	{
		cout << n << endl;
		for (int i=1;i<=n;i++) cout << i << " ";
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (v[sum-a[i]]==1)
		{
			cout << n-1 << endl;
			for (int j=1;j<=n;j++)
			{
				if (j!=i) cout << j << " ";
			}
			return;
		}
	}
	return;
}

int main()
{
	init();
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
		cout << endl;
	}
	return 0;
}
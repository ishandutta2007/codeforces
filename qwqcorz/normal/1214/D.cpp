#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=1e6;
const int p1=998244853;
const int p2=1e9+9;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

string a[N];

signed main()
{
	int n=read(),m=read();
	for (int i=0;i<n;i++) cin>>a[i];
	vector<vector<ull>>F(n,vector<ull>(m)),G(F),F1(F),G1(F),F2(F),G2(F);
	F1[0][0]=F2[0][0]=F[0][0]=1;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	if (a[i][j]=='.')
	{
		if (i) F1[i][j]+=F1[i-1][j];
		if (j) F1[i][j]+=F1[i][j-1];
		F1[i][j]%=p1;
		if (i) F2[i][j]+=F2[i-1][j];
		if (j) F2[i][j]+=F2[i][j-1];
		F2[i][j]%=p2;
		if (i) F[i][j]+=F[i-1][j];
		if (j) F[i][j]+=F[i][j-1];
	}
	G1[n-1][m-1]=G2[n-1][m-1]=G[n-1][m-1]=1;
	for (int i=n-1;i>=0;i--)
	for (int j=m-1;j>=0;j--)
	if (a[i][j]=='.')
	{
		if (i<n-1) G1[i][j]+=G1[i+1][j];
		if (j<m-1) G1[i][j]+=G1[i][j+1];
		G1[i][j]%=p1;
		if (i<n-1) G2[i][j]+=G2[i+1][j];
		if (j<m-1) G2[i][j]+=G2[i][j+1];
		G2[i][j]%=p2;
		if (i<n-1) G[i][j]+=G[i+1][j];
		if (j<m-1) G[i][j]+=G[i][j+1];
	}
	if (G1[0][0]==0&&G2[0][0]==0&&G[0][0]==0) return puts("0"),0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	if (i||j) if (i<n-1||j<m-1)
	if (F[i][j]*G[i][j]==G[0][0])
	if (1LL*F1[i][j]*G1[i][j]%p1==G1[0][0])
	if (1LL*F2[i][j]*G2[i][j]%p2==G2[0][0])
	return puts("1"),0;
	puts("2");
	
	return 0;
}
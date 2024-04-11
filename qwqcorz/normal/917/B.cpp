#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N][26];
int sg[N][N][26];
int f(int x,int y,int i)
{
	if (~sg[x][y][i]) return sg[x][y][i];
	for (int j=i;j<26;j++)
	for (int to:e[x][j])
	if (!f(y,to,j)) return sg[x][y][i]=1;
	return sg[x][y][i]=0;
}
void GreenDay()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		char c; cin>>c;
		e[u][c-'a'].push_back(v);
	}
	memset(sg,-1,sizeof(sg));
	for (int i=1;i<=n;i++,putchar('\n'))
	for (int j=1;j<=n;j++)
	putchar("BA"[f(i,j,0)]);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
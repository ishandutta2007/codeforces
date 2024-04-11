#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=50;
int f[M][2][2];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,a,b;

int solve(int a,int b)
{
	if (a<0||b<0)return 0;
	memset(f,0,sizeof(f));
	f[44][1][1]=1;
	for (int i=43;i>=0;i--)
	{
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
			{
				int nextj=(j&&!((a>>i)&1ll)),nextk=(k&&!((b>>i)&1ll));
				f[i][nextj][nextk]+=f[i+1][j][k];
				if(((a>>i)&1)||!j)f[i][j][nextk]+=f[i+1][j][k];
				if(((b>>i)&1)||!k)f[i][nextj][k]+=f[i+1][j][k];
			}
	}
	return f[0][0][0]+f[0][1][0]+f[0][0][1]+f[0][1][1];
}

signed main()
{
	T=read();
	while(T--)
	{
		a=read(),b=read();
		cout<<solve(b,b)-solve(a-1,b)*2ll+solve(a-1,a-1)<<endl;
	}
	return 0;
}
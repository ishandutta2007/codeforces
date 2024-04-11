#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int Q,sum[M][10],g[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

int f(int k)
{
	int sum=1;
	while(k)sum*=(k%10==0?1:k%10),k/=10;
	return sum;
}

signed main()
{
	Q=read();
	for (int i=1;i<=1e6;i++)
		if (i<10)g[i]=i;
		else g[i]=g[f(i)];
	for (int i=1;i<=1e6;i++)
		sum[i][g[i]]++;
	for (int i=1;i<=1e6;i++)
		for (int j=0;j<=9;j++)
			sum[i][j]+=sum[i-1][j];
	while(Q--)
	{
		int l=read(),r=read(),x=read();
		cout<<sum[r][x]-sum[l-1][x]<<endl;
	}
	return 0;
}
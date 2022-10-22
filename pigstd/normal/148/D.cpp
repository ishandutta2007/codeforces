#include<bits/stdc++.h>
using namespace std;

const int M=1e3+10;
int w,b;
double dp[M][M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	w=read(),b=read();
	for (int i=1;i<=w;i++)
		dp[i][0]=1,dp[i][1]=i*1.0/(i+1);
	for (int i=1;i<=w;i++)
		for (int j=2;j<=b;j++)
		{
			dp[i][j]+=i*1.0/(i+j);
			dp[i][j]+=j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*i*1.0/(i+j-2)*dp[i-1][j-2];
			if (j!=2)dp[i][j]+=j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*(j-2)*1.0/(i+j-2)*dp[i][j-3];
		}
	printf("%.10lf",dp[w][b]);
	return 0;
}
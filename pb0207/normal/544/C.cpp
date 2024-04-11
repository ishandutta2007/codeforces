#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=5e2+1e1+7;

typedef long long ll;

int n,m,b,P,bug[N]; 

ll ans,f[2][N][N];

int main()
{
	scanf("%d%d%d%d",&n,&m,&b,&P);
	for(int i=1;i<=n;i++)
		scanf("%d",&bug[i]);
	int cur=1,last=0;
	f[cur][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		swap(cur,last);
		for(int j=0;j<=m;j++)
			for(int k=0;k<=b;k++)
			{
				f[cur][j][k]=f[last][j][k];
				if(j&&k>=bug[i])
					f[cur][j][k]=(f[cur][j][k]+f[cur][j-1][k-bug[i]])%P;
			}
	}
	for(int i=0;i<=b;i++)
		ans=(ans+f[cur][m][i])%P;
	printf("%lld",ans);
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int n,q[100005][2],f[505][505];
inline void upd(int &x,int y)
{
	x=addmod(x+y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf(" %c",&ch);
		q[i][0]=ch;
		if(ch=='+') scanf("%d",&q[i][1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(q[i][0]=='+')
		{
			memset(f,0,sizeof(f));
			f[0][0]=1;
			for(int j=0;j<n;j++)
				for(int k=(j>=i);k<=n;k++)
					if(f[j][k])
					{
						if(j+1!=i) upd(f[j+1][k],f[j][k]);
						if(q[j+1][0]=='-') upd(f[j+1][max(k-1,0)],f[j][k]);
						else if(q[j+1][1]<q[i][1]||(q[j+1][1]==q[i][1]&&j+1<=i))
							upd(f[j+1][k+1],f[j][k]);
						else upd(f[j+1][k],f[j][k]);
					//	printf("i=%d,j=%d,k=%d,f=%d,%d,%d\n",i,j,k,f[j][k],q[j+1][1],q[i][1]);
					}
			for(int j=1;j<=n;j++)
				upd(ans,1ll*f[n][j]*q[i][1]%mod);
		}
	printf("%d\n",ans);
	return 0;
}
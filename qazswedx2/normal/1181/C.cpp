#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ri register int
int n,m,sum[26][1005][1005];
char a[1005][1005];
ll ans=0;
inline int getcr(int u,int d,int x)
{
	//printf("u=%d,d=%d,x=%d\n",u,d,x);
	int ncr=a[u][x]-'a';
	if(sum[ncr][d][x]-sum[ncr][u-1][x]==d-u+1) return ncr;
	return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			scanf(" %c",&a[i][j]);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri k=0;k<26;k++)
			{
				sum[k][i][j]=sum[k][i-1][j];
				if(a[i][j]==k+'a') sum[k][i][j]++;
			}
	//printf("---");
	for(ri i=1;i<=n;i++)
		for(ri j=i+2;j<=n;j+=3)
		{
			int l=(j-i+1)/3,ncr1,ncr2,ncr3,sum=0;
			for(ri k=1;k<=m;k++)
			{
				ri cr1=getcr(i,i+l-1,k);
				if(cr1==-1)
				{
					sum=0;
					continue;
				}
				ri cr2=getcr(i+l,i+2*l-1,k);
				if(cr2==-1||cr1==cr2)
				{
					sum=0;
					continue;
				}
				ri cr3=getcr(i+2*l,j,k);
				if(cr3==-1||cr2==cr3)
				{
					sum=0;
					continue;
				}
				if(sum==0||ncr1!=cr1||ncr2!=cr2||ncr3!=cr3)
				{
					ans++;
					sum=1;
					ncr1=cr1;
					ncr2=cr2;
					ncr3=cr3;
					continue;
				}
				sum++;
				ans+=sum;
			}
		}
	printf("%I64d",ans);
	return 0;
}
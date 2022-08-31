#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,a[100005],b[100005],c[100005],sum[5005][5005];
bool mp[5005][5005];
vector<int> val[5005];
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i],&c[i]),val[b[i]].push_back(c[i]),mp[b[i]][c[i]]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==j) sum[i][j]=sum[i-1][j]+1;
			else sum[i][j]=sum[i-1][j];
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=n;j++)
	//		printf("i=%d,j=%d,f=%d\n",i,j,sum[i][j]);
	for(int i=1;i<=n;i++)
		sort(val[i].begin(),val[i].end());
	int tans1=0,tans2=0;
	for(int i=0;i<=n;i++)
	{
		int nw=a[i],ans1=(i>0),ans2=1;
		if(i&&!mp[nw][sum[i][nw]]) continue;
		for(int j=1;j<=n;j++)
		{
			if(j!=nw)
			{
				int sz=val[j].size();
				if(!sz) continue;
				/*if(sz==1)
				{
					int x=val[j][0];
					int ct=(sum[i][j]>=x)+(sum[n][j]-sum[i][j]>=x);
					if(ct) ans1++,ans2=1ll*ans2*ct%mod;
					continue;
				}*/
				int ct1=0,ct2=0;
				for(int k=0;k<sz;k++)
				{
					int x=val[j][k];
					int ct=(sum[i][j]>=x)+(sum[n][j]-sum[i][j]>=x);
					if(ct==1) ct2++;
					if(ct==2) ct1++;
				}
			//	printf("i=%d,j=%d,ct=%d,%d\n",i,j,ct1,ct2);
				if(!ct1&&!ct2) continue;
				if(ct1==1&&!ct2)
				{
					ans1++;
					ans2=2*ans2%mod;
				}
				else if(ct2&&!ct1)
					ans1++,ans2=1ll*ans2*ct2%mod;
				else
				{
					ans1+=2;
					ans2=1ll*ans2*addmod(1ll*ct1*(ct1-1)%mod+1ll*ct1*ct2%mod)%mod;
				}
			}
			else
			{
				int sz=val[j].size();
				int ct1=0,ct2=0;
				for(int k=0;k<sz;k++)
				{
					int x=val[j][k];
					if(x==sum[i][nw]) continue;
					int ct=(sum[n][j]-sum[i][j]>=x);
					if(ct==1) ct1++;
				}
				if(!ct1) continue;
				ans1++;
				ans2=1ll*ans2*ct1%mod;
			}
		}
	//	printf("i=%d,ans1=%d,ans2=%d\n",i,ans1,ans2);
		if(ans1>tans1) tans1=ans1,tans2=ans2;
		else if(ans1==tans1) tans2=addmod(ans2+tans2);
	}
	printf("%d %d\n",tans1,tans2);
	return 0;
}
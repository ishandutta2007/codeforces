#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,num[N][30];
char buf[N];
string s; 
int main(){
	ll t,k,i,j,sm,x,ans;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&k);
		scanf("%s",&buf);
		s=buf;
		for(i=0;i<k;i++)
		{
			for(j=0;j<30;j++)
			{
				num[i][j]=0;
			}
		}
		for(i=0;i<k;i++)
		{
			for(j=i;j<n;j+=k)
			{
				num[min(i,k-i-1)][(s[j]-'a')]++;
			}
		}
		ans=0;
		for(i=0;i<k;i++)
		{
			if(i>k-i-1)
			{
				break;
			}
			sm=0;
			x=0;
			for(j=0;j<30;j++)
			{
				sm+=num[i][j];
				x=max(x,num[i][j]);
			}
			ans+=sm-x;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
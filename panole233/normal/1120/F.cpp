#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
int n,c,d,a[100101],p[100010];
long long f[2],g[2],nw;
char s[5];

int main()
{
	scanf("%d%d%d",&n,&c,&d);
	for (int i=1; i<=n; i++) scanf("%d%s",&a[i],s),p[i]=(s[0]=='P');
	scanf("%d",&a[n+1]),f[0]=0,f[1]=inf;
	for (int i=1; i<=n; i++)
	{
		int l=i;
		while (i<n&&p[i+1]==p[i]) i++;
		g[0]=f[0]+1ll*d*(i-l+1);
		nw=g[1]=f[1]+1ll*c*(a[i+1]-a[l])+1ll*d*(i-l);
		for (int j=1; j<=i-l; j++) 
			nw+=1ll*c*(a[i+1]-a[i-j+1])-d,g[1]=min(g[1],nw);
		nw=f[0]+1ll*d*(i-l+1);
		for (int j=1; j<=i-l+1; j++)
			nw+=1ll*c*(a[i+1]-a[i-j+1])-d,g[1]=min(g[1],nw);
		f[0]=g[0],f[1]=g[1];
	}
	printf("%I64d\n",min(f[0],f[1]));
	return 0;
}
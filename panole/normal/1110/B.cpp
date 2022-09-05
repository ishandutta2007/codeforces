#include<bits/stdc++.h>
using namespace std;

int n,m,k,b[100001],a[100001];

int main()
{
	scanf("%d%d%d",&n,&m,&k); b[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&b[i]),a[i-1]=b[i]-b[i-1]-1;
	sort(a+1,a+n); int ans=n;
	for (int i=1; i<=n-k; i++) ans+=a[i];
	printf("%d\n",ans);
	return 0;
}
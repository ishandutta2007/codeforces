#include<bits/stdc++.h>
using namespace std;
int rd[2020];
int main()
{
	register int n,i,x,y,ans=0;
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d %d",&x,&y),rd[x]++,rd[y]++;
	for (i=1;i<=n;i++) if (rd[i]==1) ans++;
	printf("%d",ans);
}
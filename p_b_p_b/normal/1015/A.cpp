#include<bits/stdc++.h>
#define sz 10100
using namespace std;
int a[sz],n,m;
int ans[sz];
int main()
{
	scanf("%d %d",&n,&m);
	int i,j,k,x,y,z,cnt=0,cur=0;
	while (n--) scanf("%d %d",&x,&y),a[x]++,a[y+1]--;
	for (i=1;i<=m;i++) {cur+=a[i];if (!cur) ans[++cnt]=i;}
	printf("%d\n",cnt);
	for (i=1;i<=cnt;i++) printf("%d ",ans[i]); 
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char s[5010][5010];
int can[5010][5010];
int reach[5010][5010];
int qz[5010][5010];
int main()
{
	int m,n,n1,n2;
	cin>>m>>n;
	for(n1=1;n1<=m;n1++)
	{
		getchar();
		scanf("%s",s[n1]);
	}
	memset(can,0,sizeof(can));
	memset(reach,0,sizeof(reach));
	memset(qz,0,sizeof(qz));
	int ans=0;
	for(n1=1;n1<=m;n1++)
		for(n2=0;n2<n;n2++)
			if(s[n1][n2]=='1')
			{
				can[n1][n2]=can[n1][n2-1]+1;
				reach[n2][can[n1][n2]]++;
			}
	for(n1=0;n1<n;n1++)
		for(n2=n;n2>=1;n2--)
			qz[n1][n2]=qz[n1][n2+1]+reach[n1][n2];		
	for(n1=0;n1<n;n1++)
		for(n2=1;n2<=n;n2++)
		ans=max(ans,qz[n1][n2]*n2);
	cout<<ans;
}
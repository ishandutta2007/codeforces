#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int inf=2e9+100;
int T,n,a[100005][3];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int mn=a[1][0],mx=a[1][1],mxc=a[1][2],mnc=a[1][2],qc=inf;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]<mn)
			{
				mn=a[i][0];
				mnc=a[i][2];
				qc=inf;
			}
			else if(a[i][0]==mn)
				mnc=min(mnc,a[i][2]);
			if(a[i][1]>mx)
			{
				mx=a[i][1];
				mxc=a[i][2];
				qc=inf;
			}
			else if(a[i][1]==mx)
				mxc=min(mxc,a[i][2]);
			if(a[i][0]==mn&&a[i][1]==mx)
				qc=min(qc,a[i][2]);
			printf("%d\n",min(mnc+mxc,qc));
		}
	}
}
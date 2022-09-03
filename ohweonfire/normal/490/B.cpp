#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn],n,ord[maxn],hash[maxn*5],hash2[maxn*5];
bool use[maxn*5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		if(a[i]==0)ord[2]=b[i];
		else if(b[i]==0)ord[n-1]=a[i];
		else {
			hash[a[i]]=b[i];
			hash2[b[i]]=a[i];
			use[b[i]]=true;
		}
	}
	for(int i=4;i<=n;i+=2)
		ord[i]=hash[ord[i-2]];
	if(!(n&1))
	{
		for(int i=n-3;i>=0;i-=2)
			ord[i]=hash2[ord[i+2]];
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(a[i]!=0&&!use[a[i]]&&ord[2]!=a[i])
			{
				int t=a[i];
				for(int i=1;i<=n;i+=2)
				{
					ord[i]=t;
					t=hash[t];
				}
			}
	}
	for(int i=1;i<=n;i++)printf("%d ",ord[i]);puts("");
	return 0;
}
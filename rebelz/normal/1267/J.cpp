#include <iostream>
#include <cstdio>
using namespace std;
int b[2000005],a[2000005],cnt;
inline bool pd(int x,int y)
{
	if(x==1) return 1;
	return y/(x-1)>=y%(x-1);
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=b[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			b[x]++;
		}
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i])
				a[++cnt]=b[i];
			mx=max(mx,a[cnt]);
		}
		for(int i=mx;i>=1;i--)
		{
			int flag=1;
			for(int j=1;j<=cnt;j++)
			{
				if(!pd(i,a[j]))
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				int ans=0;
				for(int j=1;j<=cnt;j++)
					ans+=(a[j]-1)/i+1;
				cout << ans << endl;
				break;
			}
		}
	}
	return 0;
}
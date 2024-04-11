#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,a[1000005],len,vis[1000005];
bool check(int x,int y)
{
	if(y%x==0||x%y==0) return 0;
	return 1;
}
bool check2(int x,int y,int z)
{
	if(check(x,y)&&check(x,z)&&check(y,z)) return 1;
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		}
		sort(a+1,a+n+1);
		len=unique(a+1,a+n+1)-a-1;
		int cnt=0,sum=0,na,nb,nc;
		for(int i=len;i>0;i--)
		{
			if(cnt>=3) break;
			if(cnt==0) 
			{
				na=a[i];
				cnt++;
				sum+=a[i];
			}
			else if(cnt==1&&check(na,a[i]))
			{
				nb=a[i];
				cnt++;
				sum+=a[i];
			}
			else if(cnt==2&&check2(na,nb,a[i]))
			{
				nc=a[i];
				cnt++;
				sum+=a[i];
			}
		}
		if(a[len]%30==0&&vis[a[len]/2]==1&&vis[a[len]/3]==1&&vis[a[len]/5]==1)
			sum=max(sum,a[len]/2+a[len]/3+a[len]/5);
		for(int i=1;i<=n;i++)
			vis[a[i]]=0;
		printf("%d\n",sum);
	}
}
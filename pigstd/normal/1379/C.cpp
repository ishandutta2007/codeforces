#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int M=1e5+10;
struct node
{
	int a,b;
}a[M];
int T,n,m,sum[M];
 
bool cmp(node a,node b)
{
	return a.a>b.a;
}
 
signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for (int i=1;i<=m;i++)
			cin>>a[i].a>>a[i].b;
		sort(a+1,a+1+m,cmp);
		int ans=0;
		for (int i=1;i<=m;i++)
			sum[i]=sum[i-1]+a[i].a;
		if (n<=m)ans=sum[n];
		else ans=sum[m] ;
		for (int i=1;i<=m;i++)
		{
			int tl=1,tr=m,p=0;
			while(tl<=tr)
			{
				int Mid=(tl+tr)/2;
				if (a[Mid].a>=a[i].b)
					tl=Mid+1,p=Mid;
				else
					tr=Mid-1;
			}
			if (p<i)
			{
				if(n-p-1>=0)
					ans=max(ans,sum[p]+a[i].a+(n-p-1)*a[i].b);
			}
			else if (p<=n)
				ans=max(ans,sum[p]+(n-p)*a[i].b);
		}
		cout<<ans<<endl;
	}
	return 0;
}
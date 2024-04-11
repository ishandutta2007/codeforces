#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
struct point
{
	long long x,y;
}a[100005];
long long s[100005],ans;
bool cmp(point x,point y)
{
	return x.x<y.x;
}
int find(long long x)
{
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (a[mid].x>=x) 
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	return r;
} 
int main()
{
	cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=a[i].y+s[i-1];
	for (int i=1;i<=n;i++)
	{
		long long p=a[i].x+d;
		int u=find(p);
		ans=max(ans,s[u]-s[i-1]);
	}
	cout << ans;
 	return 0;
}
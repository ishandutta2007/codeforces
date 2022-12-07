#include<iostream>
#include<algorithm>

int a[100010],b[100010];

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	long long ans=n;
	for(int i=1;i<=n;i++)
		ans+=max(a[i],b[i]);
	cout<<ans<<endl;
}
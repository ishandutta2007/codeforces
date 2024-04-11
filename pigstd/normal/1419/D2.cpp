#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int n,a[M],ans[M],cnt,p;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=2;i<n;i+=2)
		ans[i]=a[++cnt];
	if (n%2==0)ans[n]=a[++cnt];
	for (int i=1;i<=n;i+=2)
		ans[i]=a[++cnt];
	for (int i=2;i<n;i++)if (ans[i]<ans[i+1]&&ans[i]<ans[i-1])p++;
	cout<<p<<endl;
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
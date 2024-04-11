#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int n,a[M],ans[M];

signed main()
{
	cin>>n;int sum=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],sum^=a[i];
	if (n&1)
	{
		puts("YES");
		cout<<n-1<<endl;
		for (int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<endl;
		for (int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<endl;
	}
	else
	{
		if (sum!=0){puts("NO");return 0;}
		puts("YES");n--;
		cout<<n-1<<endl;
		for (int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<endl;
		for (int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<endl;
	}
	return 0;
}
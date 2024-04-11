#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
map<int,int>t[M];
int n,a[M],ans;

int get(int x)
{
	for (int i=30;i>=0;i--)
		if ((1<<i)&x)return i;
}

void solve(int opt)
{
	for (int i=1;i<=n;i++)
	{
		int sum=0;int p=log2(a[i]);
		for (int j=i+2;j<=n;j++)
		{
			sum+=a[j-1];
			if (sum==(a[j]^a[i]))
			{
				int l=i,r=j;
				if (opt==2)l=n-l+1,r=n-r+1,swap(l,r);
				if (t[l][r]==0)
					t[l][r]=1,ans++;//,cout<<l<<' '<<r<<endl;
			}
			if (sum>(1<<(p+1)))break;
		}
	}
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve(1);
	for (int i=1;i<=n/2;i++)
		swap(a[i],a[n-i+1]);
	solve(2);
	cout<<ans<<endl;
	return 0;
}
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

int n,a[101],b[101];

int main()
{
	cin>>n;
	n*=2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0x7fffffff;
	sort(a+1,a+n+1);
	vector<int>b;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			b.clear();
			for(int k=1;k<=n;k++)
				if(k!=i&&k!=j)
					b.push_back(a[k]);
			sort(b.begin(),b.end());
			int tot=0;
			for(int k=0;k<b.size();k+=2)
				tot+=b[k+1]-b[k];
			ans=min(ans,tot);
		}
	cout<<ans;
}
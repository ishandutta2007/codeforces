#include <bits/stdc++.h>
#define N 200010
#define INF 1e18
using namespace std;
int main(){
	long long t,n,k,i,j,a[N],mn,ans;
	vector<long long> fans;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
		}
		mn=INF;
		ans=0;
		for(j=0;j+k<n;j++)
		{
			if(mn>a[j+k]-a[j])
			{
				mn=a[j+k]-a[j];
				ans=(a[j+k]-a[j])/2+a[j];
			}
		}
		fans.push_back(ans);
	}
	for(i=0;i<fans.size();i++)
	{
		cout<<fans[i]<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	long long n,a[N],i,t,ans=0;
	vector<long long> qdh;
	cin>>n>>t;
	qdh.push_back(0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		qdh.push_back(qdh[qdh.size()-1]+a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(upper_bound(qdh.begin(),qdh.end(),(long long)qdh[i]+t)-qdh.begin()-1-i>ans)
		{
			ans=upper_bound(qdh.begin(),qdh.end(),(long long)qdh[i]+t)-qdh.begin()-1-i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
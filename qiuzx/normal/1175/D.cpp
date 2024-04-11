#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,a,i,ans;
	vector<long long> qdh;
	qdh.push_back(0);
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a;
		qdh.push_back(qdh[qdh.size()-1]+a);
	}
	qdh.erase(qdh.begin());
	ans=qdh[qdh.size()-1]*k;
	qdh.erase(qdh.begin()+qdh.size()-1);
	sort(qdh.begin(),qdh.end());
	for(i=0;i<k-1;i++)
	{
		ans-=qdh[i];
	}
	cout<<ans<<endl;
	return 0;
}
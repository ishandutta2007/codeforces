#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
int main(){
	long long n,m,ta,tb,k,a,i,pos,ans=-INF;
	vector<long long> sta,stb,arvb;
	cin>>n>>m>>ta>>tb>>k;
	for(i=0;i<n;i++)
	{
		cin>>a;
		sta.push_back(a);
		arvb.push_back(a+ta);
	}
	for(i=0;i<m;i++)
	{
		cin>>a;
		stb.push_back(a);
	}
	if(k>=n)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(i=0;i<=min(k,n);i++)
	{
		pos=lower_bound(stb.begin(),stb.end(),arvb[i])-stb.begin();
		pos+=(k-i);
		if(pos>=m)
		{
			cout<<-1<<endl;
			return 0;
		}
		ans=max(ans,stb[pos]+tb);
	}
	cout<<ans<<endl;
	return 0;
}
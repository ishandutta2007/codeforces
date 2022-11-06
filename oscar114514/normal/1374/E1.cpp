#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int t[233333],a[233333],b[233333];
vector<int> both,A,B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>a[i]>>b[i];
		if(a[i]&&b[i])both.push_back(t[i]);
		else if(a[i])A.push_back(t[i]);
		else if(b[i])B.push_back(t[i]);
	}
	if(both.size()+A.size()<k||both.size()+B.size()<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(both.begin(),both.end());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	both.push_back(0x3f3f3f3f);
	A.push_back(0x3f3f3f3f);
	B.push_back(0x3f3f3f3f);
	int i=0,j=0;
	long long ans=0;
	while(i+j<k)
	{
		if(both[i]<A[j]+B[j])ans+=both[i],i++;
		else ans+=A[j]+B[j],j++;
	}
	cout<<ans<<endl;
	return 0;
}
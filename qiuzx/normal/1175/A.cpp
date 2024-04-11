#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,k,tem,i;
	vector<long long> ans;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
		tem=0;
		while(n>0)
		{
			tem+=n%k;
			n/=k;
			if(n!=0)
			{
				tem++;
			}
		}
		ans.push_back(tem);
	}
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	bool flag=false;
	long long n,a,i;
	vector<long long> vp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		vp.push_back(a);
	}
	sort(vp.begin(),vp.end());
	while(vp.size())
	{
		flag=true;
		cout<<vp[0]<<" ";
		vp.erase(vp.begin());
		if(vp.size()<=0)
		{
			break;
		}
		cout<<vp[vp.size()-1]<<" ";
		vp.erase(vp.begin()+vp.size()-1);
	}
	if(!flag)
	{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
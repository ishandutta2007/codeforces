#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> neg,pos,zr;
int main(){
	long long i,x,ans=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x<0)
		{
			neg.push_back(x);
		}
		else if(x>0)
		{
			pos.push_back(x);
		}
		else
		{
			zr.push_back(x);
		}
	}
	sort(neg.begin(),neg.end());
	reverse(neg.begin(),neg.end());
	if(neg.size()%2==0)
	{
		for(i=0;i<pos.size();i++)
		{
			ans+=pos[i]-1;
		}
		for(i=0;i<neg.size();i++)
		{
			ans+=-1-neg[i];
		}
		ans+=zr.size();
	}
	else
	{
		if(zr.size()!=0)
		{
			for(i=0;i<pos.size();i++)
			{
				ans+=pos[i]-1;
			}
			for(i=0;i<neg.size();i++)
			{
				ans+=-1-neg[i];
			}
			ans+=zr.size();
		}
		else
		{
			for(i=0;i<pos.size();i++)
			{
				ans+=pos[i]-1;
			}
			ans+=1-neg[0];
			for(i=1;i<neg.size();i++)
			{
				ans+=-1-neg[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
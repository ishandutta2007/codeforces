#include <bits/stdc++.h>
using namespace std;
int q,n;
vector<int> a,pre;
int main(){
	int x,i;
	bool flag;
	cin>>q;
	while(q--)
	{
		cin>>n;
		n*=4;
		flag=false;
		a.clear();
		pre.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		for(i=0;i<n;i+=2)
		{
			if(a[i]!=a[i+1])
			{
				flag=true;
				break;
			}
			pre.push_back(a[i]);
		}
		if(flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		x=pre[0]*pre[pre.size()-1];
		for(i=1;i*2<pre.size();i++)
		{
			if(x!=pre[i]*pre[pre.size()-i-1])
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
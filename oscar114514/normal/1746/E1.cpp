#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"! "<<1<<endl;
		return 0;
	}
	else if(n==2)
	{
		cout<<"! "<<1<<endl;
		string tmp;
		cin>>tmp;
		if(tmp==":)")return 0;
		cout<<"! "<<2<<endl;
		return 0;
	}
	auto ask=[&](const vector<int> &tmp)
	{
		cout<<"? "<<tmp.size();
		for(auto z:tmp)cout<<' '<<z;
		cout<<endl;
		string z;
		cin>>z;
		return z=="YES";
	};
	vector<int> rem;
	for(int i=1;i<=n;i++)rem.push_back(i);
	while(rem.size()>3)
	{
		vector<int> sz(4,rem.size()/4);
		for(int i=0;i<(int)rem.size()%4;i++)
			sz[i]++;
		int now=0;
		vector<vector<int>> q(4);
		for(int t=0;t<4;t++)
		{
			for(int i=0;i<sz[t];i++)
				q[t].push_back(rem[now++]);
		}
		vector<int> tmp1=q[0],tmp2=q[0];
		tmp1.insert(tmp1.end(),q[1].begin(),q[1].end());
		tmp2.insert(tmp2.end(),q[2].begin(),q[2].end());
		int x=ask(tmp1);
		int y=ask(tmp2);
		int sum=x*2+y;
		rem.clear();
		for(int t=0;t<4;t++)
		{
			if(t!=sum)
				rem.insert(rem.end(),q[t].begin(),q[t].end());
		}
	}
	int x=ask({rem[0]});
	if(x)
	{
		int y=ask({rem[1]});
		string tmp;
		cout<<"! "<<rem[0]<<endl;
		cin>>tmp;
		if(tmp==":)")return 0;
		else if(y)cout<<"! "<<rem[1]<<endl;
		else cout<<"! "<<rem[2]<<endl;
	}
	else
	{
		int y=ask({rem[0]});
		if(y==0)
		{
			string tmp;
			cout<<"! "<<rem[1]<<endl;
			cin>>tmp;
			if(tmp==":)")return 0;
			cout<<"! "<<rem[2]<<endl;
			return 0;
		}
		y=ask({rem[1]});
		string tmp;
		cout<<"! "<<rem[0]<<endl;
		cin>>tmp;
		if(tmp==":)")return 0;
		else if(y)cout<<"! "<<rem[1]<<endl;
		else cout<<"! "<<rem[2]<<endl;
	}
	return 0;
}
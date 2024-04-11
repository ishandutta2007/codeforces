#include<bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int d[1010];
set<int> s;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
		d[t1]++;
		d[t2]++;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1)
			s.insert(i);
	while(1)
	{
		if(s.size()==1)
		{
			cout<<"! "<<*s.begin()<<endl;
			fflush(stdout);
			return 0;
		}
		int t1=*s.begin();
		s.erase(t1);
		int t2=*s.begin();
			s.erase(t2);
		cout<<"? "<<t1<<' '<<t2<<endl;
		fflush(stdout);
		int t3;
		cin>>t3;
		if(t3==t1)
		{
			cout<<"! "<<t1<<endl;
			fflush(stdout);
			return 0;
		}
		if(t3==t2)
		{
			cout<<"! "<<t2<<endl;
			fflush(stdout);
			return 0;
		}		
		for(int i=0;i<v[t1].size();i++)
		{
			d[v[t1][i]]--;
			if(d[v[t1][i]]==1)
				s.insert(v[t1][i]);
		}
		for(int i=0;i<v[t2].size();i++)
		{
			d[v[t2][i]]--;
			if(d[v[t2][i]]==1)
				s.insert(v[t2][i]);
		}
	}
		
}
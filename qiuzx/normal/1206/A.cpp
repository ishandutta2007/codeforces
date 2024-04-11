#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a,b;
int main(){
	int i,j,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(find(a.begin(),a.end(),a[i]+b[j])==a.end()&&find(b.begin(),b.end(),a[i]+b[j])==b.end())
			{
				cout<<a[i]<<" "<<b[j]<<endl;
				return 0;
			}
		}
	}
	return 0;
}
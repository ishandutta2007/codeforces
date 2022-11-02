#include <bits/stdc++.h>
using namespace std;
vector<int> vo,vz;
int main()
{
	int n;
	string s;
	cin>>s;
	n=s.size();
	int mo=n+1,mz=-1;
	for(int i=0;i<n;i++) if(s[i]=='(') vo.push_back(i+1);
	for(int i=n-1;i>=0;i--) if(s[i]==')') vz.push_back(i+1);
	if(vo.empty() || vz.empty() || vo[0]>vz[0]) {cout<<0; return 0;}
	cout<<1<<endl;
	for(int t=1;t<min(vo.size(),vz.size());t++)
	{
		if(vo[t]>vz[t])
		{
			cout<<2*t<<endl;
			for(int i=0;i<t;i++) cout<<vo[i]<<" ";
			for(int i=t-1;i>=0;i--) cout<<vz[i]<<" ";
			return 0;
		}
	}
	int t=min(vo.size(),vz.size());
	cout<<2*t<<endl;
	for(int i=0;i<t;i++) cout<<vo[i]<<" ";
	for(int i=t-1;i>=0;i--) cout<<vz[i]<<" ";		
}
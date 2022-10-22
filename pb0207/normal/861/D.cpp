#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

map<string,int>m,c;

int n;

string s[70001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j<s[i].size();j++)
				m[s[i].substr(t,j-t+1)]++;
	}
	for(int i=1;i<=n;i++)
	{
		c.clear();
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j<s[i].size();j++)
				c[s[i].substr(t,j-t+1)]++;
		string ans;
		int now=11;
		for(int t=0;t<s[i].size();t++)
			for(int j=t;j-t+1<now&&j<s[i].size();j++)
				if(m[s[i].substr(t,j-t+1)]-c[s[i].substr(t,j-t+1)]==0)
					ans=s[i].substr(t,j-t+1),now=j-t+1;
		cout<<ans<<endl;
	}	
}
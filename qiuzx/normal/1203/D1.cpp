#include <bits/stdc++.h>
using namespace std;
string s,t;
bool check(string q)
{
	int i=0,pos=0;
	while(pos!=-1&&i<t.size())
	{
		pos=q.find(t[i]);
		q=q.substr(pos+1);
		i++;
	}
	if(pos==-1)
	{
		return false;
	}
	return true;
}
int main(){
	string tem;
	int i,j;
	cin>>s>>t;
	for(i=s.size()-t.size();i>0;i--)
	{
		for(j=0;j+i<=s.size();j++)
		{
			tem=s.substr(0,j)+s.substr(j+i);
			//cout<<tem<<endl;
			if(check(tem))
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int main(){
	int i,j,pos=0,k,n,l,r,mid,all=0,p;
	vector<int> sz;
	string s="",tem;
	cin>>k;
	while(cin>>tem)
	{
		s+=tem+" ";
		all+=tem.size()+1;
	}
	all--;
	s=s.substr(0,s.size()-1);
	sz.push_back(0);
	for(i=0;i<s.size();i++)
	{
		if(s[i]==' '||s[i]=='-')
		{
			sz.push_back(i+1);
		}
	}
	sz.push_back(i);
	l=0;
	r=all+1;
	while(l+1<r)
	{
		mid=(l+r)/2;
		j=0;
		p=0;
		for(i=0;i<sz.size();)
		{
			pos=upper_bound(sz.begin(),sz.end(),sz[i]+mid)-sz.begin();
			if(pos>=sz.size())
			{
				break;
			}
			p=max(sz[pos]-sz[i],p);
			i=pos-1;
			j++;
			if(j>k)
			{
				break;
			}
		}
		j++;
		if(j<=k)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	cout<<r<<endl;
	return 0;
}
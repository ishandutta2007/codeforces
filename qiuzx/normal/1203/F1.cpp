#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<int,int> > pos,neg;
int n,r;
bool flag;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.F+a.S>b.F+b.S)
	{
		return true;
	}
	return false;
}
int main(){
	int i,a,b;
	cin>>n>>r;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(b>=0)
		{
			pos.push_back(make_pair(a,b));
		}
		else
		{
			neg.push_back(make_pair(a,b));
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),cmp);
	for(i=0;i<pos.size();i++)
	{
		if(r<pos[i].F)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		r+=pos[i].S;
	}
	while(neg.size())
	{
		flag=false;
		for(i=0;i<neg.size();i++)
		{
			if(r>=neg[i].F)
			{
				flag=true;
				r+=neg[i].S;
				neg.erase(neg.begin()+i);
				break;
			}
		}
		if(!flag||r<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
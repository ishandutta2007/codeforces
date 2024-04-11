#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Point;
Point p[4];
int main() 
{
	for(int i=1;i<=3;i++) 
	{
		cin>>p[i].second>>p[i].first;
	}
	sort(p+1,p+4);
	int l=p[1].second,r=p[1].second;
	for(int i=1;i<=3;i++) 
	{
		l=min(l,p[i].second);
		r=max(r,p[i].second);
	} 
	if(l==r) 
	{
		cout<<2<<endl;
	}
	else 
	{
		cout<<3<<endl;
		cout<<l<<' '<<p[2].first<<' '<<r<<' '<<p[2].first<<endl;
	}
	for(int i=1;i<=3;i++) 
	{
		if(i==2)
		{
			continue;
		}
		cout<<p[i].second<<' '<<p[i].first<<' '<<p[i].second<<' '<<p[2].first<<endl;
	}
}
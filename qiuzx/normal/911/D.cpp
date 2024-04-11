#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
bool orig;
int main(){
	int x,y,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	x=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(v[j]<v[i])
			{
				x++;
			}
		}
	}
	orig=x%2;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		if(((y-x)*(y-x+1)/2)%2==1)
		{
			orig=!orig;
			if(orig)
			{
				cout<<"odd"<<endl;
			}
			else
			{
				cout<<"even"<<endl;
			}
		}
		else
		{
			if(orig)
			{
				cout<<"odd"<<endl;
			}
			else
			{
				cout<<"even"<<endl;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> x;
int n,cnt;
int main(){
	int i;
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cnt=n*2;
	cout<<1<<" ";
	x.push_back(2);
	for(i=1;i<n;i++)
	{
		cout<<cnt<<" ";
		if(i%2==1)
		{
			x.push_back(cnt-1);
			cnt-=3;
		}
		else
		{
			x.push_back(cnt+1);
			cnt--;
		}
	}
	for(i=0;i<x.size();i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	return 0;
}
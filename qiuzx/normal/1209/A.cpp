#include <bits/stdc++.h>
#define N 110
using namespace std;
int n,ans=0;
vector<int> a;
bool book[N]={};
int main(){
	int i,j,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++)
	{
		if(book[i])
		{
			continue;
		}
		book[i]=true;
		ans++;
		for(j=i+1;j<a.size();j++)
		{
			if(a[j]%a[i]==0)
			{
				book[j]=true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
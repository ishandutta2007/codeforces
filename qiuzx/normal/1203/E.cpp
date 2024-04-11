#include <bits/stdc++.h>
#define N 150010
using namespace std;
bool book[N];
int n;
vector<int> a;
int main(){
	int x,i,ans=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++)
	{
		if(!book[a[i]-1]&&a[i]!=1)
		{
			book[a[i]-1]=true;
			ans++;
		}
		else if(!book[a[i]])
		{
			book[a[i]]=true;
			ans++;
		}
		else if(!book[a[i]+1])
		{
			book[a[i]+1]=true;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
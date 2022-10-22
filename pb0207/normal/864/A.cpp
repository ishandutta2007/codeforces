#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],vis[N];

vector<int>ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],vis[a[i]]++;
	int cnt=0;
	for(int i=1;i<=100;i++)
		if(vis[i])
			cnt++,ans.push_back(i);
	if(cnt!=2)
	{
		cout<<"NO";
		return 0;
	}
	if(vis[ans[0]]!=vis[ans[1]])
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<ans[0]<<" "<<ans[1];
}
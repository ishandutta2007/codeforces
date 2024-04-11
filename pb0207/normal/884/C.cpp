#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>r;

int n,p[100001],vis[100001];

long long ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int x=i;
			vis[x]=1;
			int cnt=1;
			while(!vis[p[x]])
				x=p[x],vis[x]=1,cnt++;
			r.push_back(cnt);
		}
	if(r.size()==1)
	{
		cout<<1ll*r[0]*r[0];
		return 0;
	}
	sort(r.begin(),r.end());
	r[r.size()-2]+=r[r.size()-1];
	for(int i=0;i<r.size()-1;i++)
		ans+=1ll*r[i]*r[i];
	cout<<ans;
}
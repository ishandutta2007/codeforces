#include <bits/stdc++.h>
#define N 2010
using namespace std;
bool mp[N][N]={};
int main(){
	int n,a,b,x,y,i,j,ans=0;
	vector<pair<int,int> > vp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		vp.push_back(make_pair(a+1000,b+1000));
		mp[a+1000][b+1000]=true;
	}
	for(i=0;i<vp.size();i++)
	{
		for(j=i+1;j<vp.size();j++)
		{
			a=vp[i].first;
			b=vp[i].second;
			x=vp[j].first;
			y=vp[j].second;
			if((a+x)%2==1||(b+y)%2==1||!mp[(a+x)/2][(b+y)/2])
			{
				continue;
			}
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
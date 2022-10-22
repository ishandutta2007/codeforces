#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=2e5+1e3+7;

int n,k;

int t[N],ans,last=-1;

vector<int>d;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]),ans+=(t[i]<0);
	if(ans>k)
	{
		cout<<"-1";
		return 0;
	}
	k-=ans;
	ans<<=1;
	for(int i=1;i<=n;i++)
		if(t[i]<0)
		{
			if(last!=-1)
				d.push_back(i-last-1);
			last=i;
		}
	sort(d.begin(),d.end());
	for(int i=0;i<d.size();i++)
	{
		if(k<d[i])
			break;
		k-=d[i];
		ans-=2;
	}
	if(k>n-last-1)
		ans--;
	cout<<ans;
}
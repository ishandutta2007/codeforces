#include <bits/stdc++.h>
#define N 55
using namespace std;
vector<int> vt[N],v;
int n,k,num,ans=1000000000;
int main(){
	int i,j,l,x;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		x=v[i];
		while(x>0)
		{
			vt[i].push_back(x);
			x/=2;
		}
		vt[i].push_back(0);
	}
	for(l=0;l<n;l++)
	{
		for(i=0;i<vt[l].size();i++)
		{
			num=0;
			x=0;
			for(j=0;j<n;j++)
			{
				if(x>=k)
				{
					break;
				}
				if(find(vt[j].begin(),vt[j].end(),vt[l][i])!=vt[j].end())
				{
					x++;
					num+=find(vt[j].begin(),vt[j].end(),vt[l][i])-vt[j].begin();
				}
			}
			if(x>=k)
			{
				ans=min(ans,num);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
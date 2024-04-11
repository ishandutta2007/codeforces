#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec;
ll arr[200001],used[200001];
ll res,n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		vec.clear();
		for (i=1;i<=n;i++)
		{
			cin>>arr[i];
			used[i]=0;
			vec.push_back(i);
		}
		res=m*(n-1);
		sort(vec.begin(),vec.end(),[](int a, int b){
			return (arr[a]<arr[b]);
		});
		for (auto g : vec)
		{
			if (used[g]) continue;
			if (arr[g]>=m) break;
			int l=g,r=g;
			used[g]=1;
			for (l=g-1;l>=1;l--)
			{
				if ((used[l])or(arr[l]%arr[g])) break;
				else 
				{
					res-=m-arr[g];
					used[l]=1;
				}
			}
			if ((l>=1)and(used[l])and(arr[l]%arr[g]==0)) 
					res-=m-arr[g];
			for (r=g+1;r<=n;r++)
			{
				if ((used[r])or(arr[r]%arr[g])) break;
				else 
				{
					res-=m-arr[g];
					used[r]=1;
				}
			}
			if ((r<=n)and(used[r])and(arr[r]%arr[g]==0)) 
					res-=m-arr[g];
		}
		cout<<res<<endl;
	}
}
#include <bits/stdc++.h>
#define SIZE 1005
#define INF 0x3f3f3f3f
using namespace std;
int res[SIZE];
vector<int> v;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,x;
	cin>>n;
	memset(res,INF,sizeof(res));
	for(int i=0;i<=log2(n)+1;i++)
	{
		for(int val=0;val<=1;val++)
		{
			v.clear();
			for(int j=0;j<n;j++)
			{
				if(((j>>i)&1)==val) v.push_back(j);
			}
			int len=v.size();
			if(len==n||len==0) continue;
			cout<<len<<endl;
			for(int j=0;j<len;j++)
			{
				if(j!=0) cout<<" ";
				cout<<v[j]+1;
			}
			cout<<endl;
			for(int j=0;j<n;j++)
			{
				cin>>x;
				if(((j>>i)&1)==(val^1)) res[j]=min(res[j],x);
			}
		}
	}
	cout<<-1<<endl;
	for(int i=0;i<n;i++) cout<<res[i]<<" ";
	cout<<endl;
}
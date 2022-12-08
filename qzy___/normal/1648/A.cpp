#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n,m,s,A,x;
vector<int>a[N],b[N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>x,a[x].push_back(i),b[x].push_back(j);
	for(int i=1;i<N;i++)
	{
		sort(a[i].begin(),a[i].end()),s=0;
		for(int j=0;j<a[i].size();j++)
			s+=a[i][j];
		for(int j=0;j<a[i].size();j++)
			s-=a[i][j],A+=s-a[i][j]*(a[i].size()-j-1);
	}
	for(int i=1;i<N;i++)
	{
		sort(b[i].begin(),b[i].end()),s=0;
		for(int j=0;j<b[i].size();j++)
			s+=b[i][j];
		for(int j=0;j<b[i].size();j++)
			s-=b[i][j],A+=s-b[i][j]*(b[i].size()-j-1);
	}
	cout<<A;
}
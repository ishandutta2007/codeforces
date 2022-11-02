#include <bits/stdc++.h>
#define MAXN 5007
using namespace std;
int a[MAXN],y[MAXN];
int cnt[2*MAXN];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<MAXN;i++) y[i]=3*(n*(i+10000))+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) a[i]+=min(i-j,j-1);
	if(m>a[n]) {cout<<-1; return 0;}
	for(int t=1;t<=n;t++) if(a[t]>=m)
	{
		int x=t;
		for(int i=1;i<x;i++) cout<<i<<" ";
		for(int i=1;i<x;i++) for(int j=i+1;j<x;j++) cnt[i+j]++;
		int res=a[x],br=x;
		while(res!=m) 
		{
			res-=cnt[br++];
			res+=cnt[br];
		}
		cout<<br<<" ";
		for(int i=0;i<n-x;i++) cout<<y[i]<<" ";
		return 0;
	}
}
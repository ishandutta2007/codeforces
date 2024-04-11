#include<bits/stdc++.h>
using namespace std;

const int M=55;
int a[M],minn=9999999,n,m;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+1+m);
	for (int i=1;i<=m-n+1;i++)
		minn=min(minn,a[i+n-1]-a[i]);
	cout<<minn;
}
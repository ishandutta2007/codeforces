#include <bits/stdc++.h>
using namespace std;
pair<int,int> p[500000];
int a[500001],b[500001];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) p[i].second=i;
	for(int i=0;i<n;i++) p[i].first=a[i]+a[i+1];
	p[n-1].first+=a[0];
	sort(p,p+n);
	for(int i=0;i<n;i++) b[p[i].second]=i;
	for(int i=0;i<n;i++) cout<<b[i]<<" ";
}
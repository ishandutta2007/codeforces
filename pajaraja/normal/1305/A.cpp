#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int a[MAXN],b[MAXN];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n); sort(b,b+n);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++) cout<<b[i]<<" ";
		cout<<endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,a[1000],t[1000],x[1000],y[1000],ok;
int main()
{
 cin>>n>>m;
	for (i=0;i<m;i++) {cin>>t[i]>>x[i]>>y[i]; x[i]--; y[i]--;}
	for (i=1;i<n;i++) a[i]=-1;
	for (i=0;i<m;i++) 
	if (t[i])
	{
	for (j=x[i]+1; j<=y[i]; j++) a[j]=1;
	}
	for (i=0;i<m;i++) 
	if (!t[i])
	{
	ok=1;
	for (j=x[i]+1; j<=y[i]; j++) { if (a[j]==-1) ok=0;}
	if (ok) {cout<<"No"; return 0;}
	}
	cout<<"Yes"<<endl;
	ok=500000000; cout<<ok<<' ';
	for (i=1;i<n;i++) {ok+=a[i]; cout<<ok<<' ';}
}
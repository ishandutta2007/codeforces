#include<cstdio>
#include<iostream>
using namespace std;

int n,a,ans;

double sig;

int main()
{
	cin>>n>>a;
	double k=n;
	sig=180.0*(k-2.0)/k;
	sig=(180.0-sig)/2.0;
	double aa=a;
	ans=aa/sig;
	if(aa-sig*(double)(ans)>sig*(double)(ans+1)-aa)
		ans++;
	ans=max(ans,1);
	ans=min(ans,n-2);
	cout<<2<<" "<<1<<" "<<2+ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double l,res=0;
	cin>>n>>l;
	double tab[n];
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
	}
	sort(tab,tab+n);
	res=max(res,tab[0]);
	res=max(res,l-tab[n-1]);
	for(int i=0;i<n-1;i++)
	{
		res=max(res,(tab[i+1]-tab[i])/2);
	}
	cout<<fixed<<setprecision(9)<<res;
	
	return 0;
}
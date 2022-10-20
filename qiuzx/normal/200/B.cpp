#include <bits/stdc++.h>
using namespace std;
int main(){
	int i;
	double o=0,ans,a,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		o+=a/100;
	}
	ans=o/n*100;
	cout<<ans<<endl;
	return 0;
}
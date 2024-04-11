#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,h,a,i,ans=0;
	cin>>n>>h;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a>h)
		{
			ans++;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
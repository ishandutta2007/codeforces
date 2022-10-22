#include<bits/stdc++.h>
using namespace std;

int n,a1,a2,a3,b1,b2,b3;
int ans1,ans2;

int main()
{
	cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
	ans2=min(a3,b1)+min(a1,b2)+min(a2,b3);
	ans1=n-min(a1,n-b2)-min(a2,n-b3)-min(a3,n-b1);
	cout<<ans1<<' '<<ans2;
	return 0;
}
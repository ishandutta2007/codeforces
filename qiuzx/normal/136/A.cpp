#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,a,ans[105];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ans[a-1]=i+1;
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
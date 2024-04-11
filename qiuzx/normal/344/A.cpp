#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,i,ans=1;
	cin>>n;
	n--;
	cin>>b;
	for(i=0;i<n;i++)
	{
		a=b;
		cin>>b;
		if(a!=b)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
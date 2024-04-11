#include <bits/stdc++.h>
using namespace std;
int main(){
	long long q,n,a,b,i,ans[520];
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>n>>a>>b;
		if(a<=b/2)
			ans[i]=n*a;
		else
		{
			if(n%2==0)
				ans[i]=n/2*b;
			else
				ans[i]=n/2*b+a;
		}
	}
	for(i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}
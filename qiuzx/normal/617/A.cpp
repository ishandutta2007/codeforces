#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,i;
	cin>>n;
	while(n!=0)
	{
		for(i=5;i>0;i--)
		{
			if(n>=i)
			{
				break;
			}
		}
		ans+=n/i;
		n%=i;
	}
	cout<<ans<<endl;
	return 0;
}
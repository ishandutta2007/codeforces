#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<max_element(a+1,a+n+1)-a<<' '<<min_element(a+1,a+n+1)-a<<endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int s=a[1],same=0;
		for(int i=1;i<=n;i++)if(a[i]!=s)same=1;
		if(same)cout<<1<<endl;
		else cout<<n<<endl;
	}
	return 0;
}
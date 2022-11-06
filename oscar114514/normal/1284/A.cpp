#include<bits/stdc++.h>
using namespace std;
int n,k,q,x;
string s[2333],t[2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>t[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>x;
		cout<<s[(x-1)%n+1]<<t[(x-1)%k+1]<<endl;
	}
	return 0;
}
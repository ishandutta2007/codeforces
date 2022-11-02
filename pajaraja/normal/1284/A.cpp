#include <bits/stdc++.h>
using namespace std;
string s[50],t[50];
int main()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>t[i];
	int q;
	cin>>q;
	while(q--)
	{
		int x; cin>>x; x--;
		cout<<s[x%n]<<t[x%m]<<endl;
	}
}
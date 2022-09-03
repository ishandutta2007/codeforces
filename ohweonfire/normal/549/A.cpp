#include <bits/stdc++.h>
using namespace std;
string s[55];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=0;j<m-1;j++)
		{
			string tmp="";
			tmp+=s[i][j];
			tmp+=s[i][j+1];
			tmp+=s[i+1][j];
			tmp+=s[i+1][j+1];
			sort(tmp.begin(),tmp.end());
			if(tmp=="acef")ans++;
		}
	cout<<ans<<endl;
	return 0;
}
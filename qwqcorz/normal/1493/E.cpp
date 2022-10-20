#include<bits/stdc++.h>
using namespace std;

string a,b;
string dec(string b)
{
	int i=b.length()-1,n=i+1;
	while (b[i]=='0') i--;
	b[i]='0';
	for (int j=i+1;j<n;j++) b[j]='1';
	return b;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n>>a>>b;
	if (a[0]!=b[0]) for (int i=1;i<=n;i++) cout<<'1';
	else if (b[n-1]=='0'&&a!=b&&dec(b)!=a) b[n-1]='1',cout<<b;
	else cout<<b;
	
	return 0;
}
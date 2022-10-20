//copyright qiuzx
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	string s[50],t[50]; 
	int n,m,i,q,x;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>t[i];
	}
	cin>>q;
	for(i=0;i<q;i++)	
	{
		cin>>x;
		cout<<s[(x-1)%n]<<t[(x-1)%m]<<endl;
	}
	return 0;
}
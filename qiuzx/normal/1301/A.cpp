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
	int t,i;
	string a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		for(i=0;i<a.size();i++)
		{
			if(c[i]==a[i]||c[i]==b[i])
			{
				continue;
			}
			i=-1;
			break;
		}
		if(i==-1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
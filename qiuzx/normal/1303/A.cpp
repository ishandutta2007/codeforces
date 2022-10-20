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
	int t,ans=0,i,pos,p2;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		pos=s.rfind('1');
		p2=s.find('1');
		ans=0;
		for(i=p2+1;i<pos;i++)
		{
			if(s[i]=='0')
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
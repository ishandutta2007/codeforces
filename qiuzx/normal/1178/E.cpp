#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n;
string s;
string ans="",ans2="";
int main(){
	ll st,i,j;
	cin>>s;
	n=s.size();
	if(n<5)
	{
		if(n<=3)
		{
			cout<<s[0]<<endl;
			return 0;
		}
		if(s[2]==s[0])
		{
			cout<<s[0]<<s[1]<<s[2]<<endl;
			return 0;
		}
		if(s[3]==s[0])
		{
			cout<<s[0]<<s[1]<<s[3]<<endl;
			return 0;
		}
		cout<<s[1]<<s[2]<<s[3]<<endl;
		return 0;
	}
	st=n/2;
	i=j=st;
	while(i>=0&&j<n)
	{
		if(i>0&&j+1<n&&s[i-1]==s[j+1])
		{
			ans+=s[i-1];
			ans2+=s[j+1];
		}
		else if(i>0&&j+2<n&&s[i-1]==s[j+2])
		{
			ans+=s[i-1];
			ans2+=s[j+2];
			j++;
		}
		else if(i>1&&j+1<n&&s[i-2]==s[j+1])
		{
			ans+=s[i-2];
			ans2+=s[j+1];
			i--;
		}
		else if(i>1&&j+2<n&&s[i-2]==s[j+2])
		{
			ans+=s[i-2];
			ans2+=s[j+2];
			i--;
			j++;
		}
		i--;
		j++;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<s[st]<<ans2<<endl;
	return 0;
}
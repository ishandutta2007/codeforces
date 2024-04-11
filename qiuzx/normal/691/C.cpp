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
#define N 100010
using namespace std;
string s,ans="";
string cge(string bef)
{
	ll i,l,r;
	for(l=0;l<bef.size();l++)
	{
		if(bef[l]!='0')
		{
			break;
		}
	}
	for(r=bef.size()-1;r>=0;r--)
	{
		if(bef[r]!='0'&&bef[r]!='.')
		{
			break;
		}
		if(bef[r]=='.')
		{
			r--;
			break;
		}
	}
	return bef.substr(l,r-l+1);
}
int main(){
	ll i,x;
	cin>>s;
	if(s.find('.')==-1)
	{
		s+='.';
	}
	s=cge(s);
	if(s.find('.')==-1)
	{
		s+='.';
	}
	if(s[0]=='.')
	{
		for(i=1;i<s.size();i++)
		{
			if('1'<=s[i]&&s[i]<='9')
			{
				x=i;
				break;
			}
		}
		ans+=s[x];
		ans+=".";
		for(i=x+1;i<s.size();i++)
		{
			ans+=s[i];
		}
		ans=cge(ans);
		if(ans[ans.size()-1]=='.')
		{
			ans.erase(ans.end()-1);
		}
		cout<<ans<<"E-"<<x<<endl;
	}
	else
	{
		x=s.find('.');
		ans+=s[0];
		ans+=".";
		for(i=1;i<s.size();i++)
		{
			if(s[i]!='.')
			{
				ans+=s[i];
			}
		}
		ans=cge(ans);
		if(ans[ans.size()-1]=='.')
		{
			ans.erase(ans.end()-1);
		}
		cout<<ans;
		if(x!=1)
		{
			cout<<"E"<<x-1<<endl;
		}
	}
	return 0;
}
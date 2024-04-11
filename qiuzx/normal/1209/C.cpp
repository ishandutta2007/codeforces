#include <bits/stdc++.h>
#define N 200010
using namespace std;
int t,n;
string s;
string ok(string ans)
{
	int i;
	bool can=true;
	string tem1="",tem2="",st1,st2,ts=""; 
	for(i=0;i<n;i++)
	{
		ts+=ans[i];
		if(ans[i]=='1')
		{
			tem1+=s[i];
		}
		else if(ans[i]=='2')
		{
			tem2+=s[i];
			can=false;
		}
		else
		{
			if(can)
			{
				tem2+=s[i];
				ts[i]='2';
			}
			else
			{
				tem1+=s[i];
				ts[i]='1';
			}
		}
	}
	st1=tem1+tem2;
	st2=st1;
	sort(st2.begin(),st2.end());
	if(st2!=st1)
	{
		return "-";
	}
	return ts;
}
string check(int x)
{
	int i,v;
	string tem="";
	for(i=0;i<n;i++)
	{
		v=s[i]-'0';
		tem+="-";
		if(v<x)
		{
			tem[i]='1';
		}
		else if(v>x)
		{
			tem[i]='2';
		}
	}
	return ok(tem);
}
int main(){
	string ans;
	int i;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		i=0;
		ans="-";
		while(ans=="-"&&i<10)
		{
			ans=check(i);
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
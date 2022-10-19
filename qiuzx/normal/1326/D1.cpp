#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll t,ans;
string s,tmp,as,sta,stb;
bool palin(string a)
{
	int i;
	for(i=0;i<a.size();i++)
	{
		if(a[i]!=a[a.size()-i-1])
		{
			return false;
		}
	}
	return true;
}
string getstl(int x)
{
	string l="";
	ll i;
	for(i=0;i<x;i++)
	{
		l+=s[i];
	}
	return l;
}
string getstr(int x)
{
	string l="";
	ll i;
	for(i=0;i<x;i++)
	{
		l+=s[s.size()-i-1];
	}
	reverse(l.begin(),l.end());
	return l;
}
int main(){
	ll i,j;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ans=0;
		as="";
		//only left
		tmp="";
		for(i=0;i<s.size();i++)
		{
			tmp+=s[i];
			if(palin(tmp))
			{
				if(ans<tmp.size())
				{
					ans=tmp.size();
					as=tmp;
				}
			}
		}
		//only right
		tmp="";
		for(i=s.size()-1;i>=0;i--)
		{
			tmp+=s[i];
			if(palin(tmp))
			{
				if(ans<tmp.size())
				{
					ans=tmp.size();
					as=tmp;
				}
			}
		}
		//from both sides 
		i=0;
		while(i<s.size()/2&&s[i]==s[s.size()-i-1])
		{
			i++;
		}
		sta=getstl(i);
		stb=getstr(i);
		tmp="";
		for(j=i;j<=s.size()-i-1;j++)//add left 
		{
			tmp+=s[j];
			if(palin(tmp))
			{
				if(ans<sta.size()+stb.size()+tmp.size())
				{
					ans=tmp.size()+sta.size()+stb.size();
					as=sta+tmp+stb;
				}
			}
		}
		tmp="";
		for(j=s.size()-i-1;j>=i;j--)//add right
		{
			tmp+=s[j];
			if(palin(tmp))
			{
				if(ans<tmp.size()+sta.size()+stb.size())
				{
					ans=tmp.size()+sta.size()+stb.size();
					as=sta+tmp+stb;
				}
			}
		}
		cout<<as<<endl;
	}
	return 0;
}
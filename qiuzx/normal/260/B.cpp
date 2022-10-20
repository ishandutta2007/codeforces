#include <bits/stdc++.h>
using namespace std;
int daysin(int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		return 31;
	}
	if(m==4||m==6||m==9||m==11)
	{
		return 30;
	}
	return 28;
}
bool check(int d,int m,int y)
{
	if(d==-1||m==-1||y==-1)
	{
		return false;
	}
	if(y<2013||y>2015)
	{
		return false;
	}
	if(m<1||m>12)
	{
		return false;
	}
	if(d<1||d>daysin(m))
	{
		return false;
	}
	return true;
}
int main(){
	vector<string> v;
	map<string,int> mp;
	string s,ans,a;
	int i,j,d,m,y,hp=0;
	cin>>s;
	for(i=2;i+7<s.size();i++)
	{
		if(s[i]!='-')
		{
			continue;
		}
		a="";
		for(j=i-2;j<=i+7;j++)
		{
			a+=s[j];
		}
		if(a[2]!='-'||a[5]!='-')
		{
			continue;
		}
		d=m=y=0;
		for(j=0;j<2;j++)
		{
			if(!isdigit(a[j]))
			{
				d=-1;
				break;
			}
			d=d*10+(a[j]-'0');
		}
		for(j=3;j<5;j++)
		{
			if(!isdigit(a[j]))
			{
				m=-1;
				break;
			}
			m=m*10+(a[j]-'0');
		}
		for(j=6;j<10;j++)
		{
			if(!isdigit(a[j]))
			{
				y=-1;
				break;
			}
			y=y*10+(a[j]-'0');
		}
		if(check(d,m,y))
		{
			if(mp[a]==0)
			{
				v.push_back(a);
			}
			mp[a]++;
		}
	}
	for(i=0;i<v.size();i++)
	{
		if(hp<mp[v[i]])
		{
			hp=mp[v[i]];
			ans=v[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define N 12
using namespace std;
long long a,b,num[N];
string ans;
vector<int> dg,dg2;
void dfs(int x,bool adb,string s)
{
	int i;
	if(s.size()==dg.size())	
	{
		cout<<s<<endl;
		exit(0);
	}
	if(adb)
	{
		i=9;
	}
	else
	{
		i=dg2[x];
	}
	for(;i>=0;i--)
	{
		if(num[i]==0)
		{
			continue;
		}
		num[i]--;
		ans=s;
		ans+=(char)i+'0';
		if(i<dg2[x]||adb)
		{
			dfs(x+1,true,ans);
		}
		else
		{
			dfs(x+1,false,ans);
		}
		num[i]++;
	}
}
int main(){
	int i,j;
	cin>>a>>b;
	memset(num,0,sizeof(num));
	dg.clear();
	dg2.clear();
	while(a!=0)
	{
		dg.push_back(a%10);
		a/=10;
	}
	sort(dg.begin(),dg.end());
	while(b!=0)
	{
		dg2.push_back(b%10);
		b/=10;
	}
	reverse(dg2.begin(),dg2.end());
	if(dg.size()<dg2.size())
	{
		for(i=dg.size()-1;i>=0;i--)
		{
			cout<<dg[i];
		}
		cout<<endl;
		return 0;
	}
	for(i=0;i<dg.size();i++)
	{
		num[dg[i]]++;
	}
	ans="";
	dfs(0,false,ans);
	return 0;
}
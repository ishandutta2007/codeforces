#include <bits/stdc++.h>
using namespace std;
vector<int> cpc[26];
string s,tem;
bool dfs(int x,int y)
{
	if(x>=26)
	{
		return true;
	}
	int pos,i;
	char sb;
	pos=upper_bound(cpc[x].begin(),cpc[x].end(),y)-cpc[x].begin();
	if(pos>=cpc[x].size())
	{
		return false;
	}
	sb=s[cpc[x][pos]];
	s[cpc[x][pos]]=('a'+x);
	if(dfs(x+1,cpc[x][pos]))
	{
		return true;
	}
	s[cpc[x][pos]]=sb;
	return false;
}
int main(){
	char sb;
	int i,j;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		for(sb=s[i];sb<='z';sb++)
		{
			cpc[sb-'a'].push_back(i);
		}
	}
	for(i=0;i<cpc[0].size();i++)
	{
		tem=s;
		if(dfs(1,cpc[0][i]))
		{
			cout<<s<<endl;
			return 0;
		}
		s=tem;
	}
	cout<<-1<<endl;
	return 0;
}
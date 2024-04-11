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
bool book[30];
vector<int> v;
set<int> vt[30];
string s;
void dfs(int x,int lst)
{
	cout<<(char)((char)x+'a');
	book[x]=true;
	for(set<int>::iterator it=vt[x].begin();it!=vt[x].end();it++)
	{
		if(*it!=lst&&!book[*it])
		{
			dfs(*it,x);
		}
	}
	return;
}
int main(){
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.size()==1)
		{
			cout<<"YES"<<endl;
			cout<<"abcdefghijklmnopqrstuvwxyz"<<endl;
			continue;
		}
		v.clear();
		memset(book,false,sizeof(book));
		for(i=0;i<30;i++)
		{
			vt[i].clear();
		}
		for(i=0;i+1<s.size();i++)
		{
			vt[s[i]-'a'].insert(s[i+1]-'a');
			vt[s[i+1]-'a'].insert(s[i]-'a');
		}
		for(i=0;i<30;i++)
		{
			if(vt[i].size()==1)
			{
				v.push_back(i);
			}
			if(vt[i].size()>2)
			{
				cout<<"NO"<<endl;
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			continue;
		}
		if(v.size()<2||v.size()%2!=0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(i=0;i<v.size();i++)
		{
			if(!book[v[i]])
			{
				dfs(v[i],-1);
			}
		}
		for(i=0;i<26;i++)
		{
			if(vt[i].size()==0)
			{
				cout<<(char)((char)i+'a');
			}
		}
		cout<<endl;
	}
	return 0;
}
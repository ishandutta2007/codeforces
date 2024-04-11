#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

const int N=202;

map<string,int> id;

set<string> t[N];

string name[N];

int n,tot;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string na;
		cin>>na;
		if(id.find(na)==id.end())
			id[na]=++tot,name[tot]=na;
		int x=id[na];
		int k;
		cin>>k;
		for(int T=1;T<=k;T++)
		{
			string tl;
			cin>>tl;
			int sz=tl.size();
			bool flag=true;
			vector<string>er;
			er.clear();
			for(set<string>::iterator it=t[x].begin();it!=t[x].end();it++)
			{
				string now=*it;
				int len=now.size();
				if(len<sz)
				{
					if(tl.substr(sz-len,len)==now)
						er.push_back(now);
				}
				else
				{
					if(now.substr(len-sz,sz)==tl)
						flag=false;
				}
			}
			for(int j=0;j<er.size();j++)
				t[x].erase(er[j]);
			if(flag)
				t[x].insert(tl);
		}
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
	{
		cout<<name[i]<<" ";
		cout<<t[i].size()<<" ";
		for(set<string>::iterator it=t[i].begin();it!=t[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
}
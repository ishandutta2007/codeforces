#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

const int N=1e3+1e2+7;

map<string,vector<int> >m;

set<string>s;

int n,vis[N],tag[N];

string s1[N],s2[N],ans[N],ss1[N],ss2[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
		cin>>s2[i];
		ss1[i].clear();
		ss2[i].clear();
		ss1[i]=s1[i].substr(0,3);
		ss2[i]=s1[i].substr(0,2)+s2[i][0];
		m[ss1[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&(int)m[ss1[i]].size()>1)
		{
			for(int j=0;j<(int)m[ss1[i]].size();j++)
			{
				ans[m[ss1[i]][j]]=ss2[m[ss1[i]][j]];
				if(s.find(ans[m[ss1[i]][j]])!=s.end())
				{
					cout<<"NO";
					return 0;
				}
				s.insert(ans[m[ss1[i]][j]]);
				tag[m[ss1[i]][j]]=2;
				vis[m[ss1[i]][j]]=1;
			}
		}
	while(true)
	{
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
//				if(s.find(ss1[i])==s.end())
//					ans[i]=ss1[i],tag[i]=1;
//				else
//					if(s.find(ss2[i])==s.end())
//						ans[i]=ss2[i],tag[2]=2;
//					else
//					{
//						cout<<"NO";
//						exit(0);
//					}
				ok=1;
				ans[i]=ss1[i];
				tag[i]=1;
				vis[i]=1;
			}
			else
			if(tag[i]==1&&s.find(ss1[i])!=s.end())
			{
				ok=1;
				if(s.find(ss2[i])!=s.end())
				{
					cout<<"NO";
					exit(0);
				}
				else
					ans[i]=ss2[i],s.insert(ss2[i]),tag[i]=2;
			}
		}
		if(!ok)
			break;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}
/*
5
ABC DFE
ABD DD
AFD DDE
AFA DES
ABD SSS
*/
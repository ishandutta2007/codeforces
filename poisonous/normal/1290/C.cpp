#include<bits/stdc++.h>
using namespace std;
vector<int> v[300010];
int num[300010];
int x[300010][2],y[300010];
int b[300010];
int c[300010];
int now[300010][2];
string s;
int xo,tmp;
int main()
{
	int n,m;
	cin>>n>>m;
	tmp=m+1;
	cin>>s;
	for(int i=1;i<=n;i++)
		num[i]=(s[i-1]=='1');
	for(int i=1;i<=m;i++)
	{
		v[i].push_back(i);
		b[i]=i;
		int t;
		cin>>t;
		now[i][0]=1;
		for(int j=1;j<=t;j++)
		{
			int o;
			cin>>o;
			x[o][y[o]]=i;
			y[o]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(y[i]==1)
		{
			if(b[x[i][0]]==tmp)
			{
				cout<<ans<<endl;
				continue;
			}
			int sz1=v[tmp].size(),sz2=v[b[x[i][0]]].size();
			ans-=now[tmp][1^xo];
			ans-=min(now[b[x[i][0]]][0],now[b[x[i][0]]][1]);
			if(sz1<sz2)
			{
				if(c[x[i][0]]!=num[i])
				{
					for(int j=0;j<sz1;j++)
					{
						v[b[x[i][0]]].push_back(v[tmp][j]);
						c[v[tmp][j]]^=xo;
						b[v[tmp][j]]=b[x[i][0]];
						now[b[x[i][0]]][c[v[tmp][j]]]++;
					}
					xo=0;
				}
				else
				{
					for(int j=0;j<sz1;j++)
					{
						v[b[x[i][0]]].push_back(v[tmp][j]);
						c[v[tmp][j]]^=xo^1;
						b[v[tmp][j]]=b[x[i][0]];
						now[b[x[i][0]]][c[v[tmp][j]]]++;
					}
					xo=1;	
				}
				tmp=b[x[i][0]];
			}
			else
			{
				int bb=b[x[i][0]];
				if(c[x[i][0]]!=num[i])
				{
					for(int j=0;j<sz2;j++)
					{
						v[tmp].push_back(v[bb][j]);
						c[v[bb][j]]^=xo;
						b[v[bb][j]]=tmp;
						now[tmp][c[v[bb][j]]]++;
					}
				}
				else
					for(int j=0;j<sz2;j++)
					{
						v[tmp].push_back(v[bb][j]);
						c[v[bb][j]]^=xo^1;
						b[v[bb][j]]=tmp;
						now[tmp][c[v[bb][j]]]++;
					}
			}
			ans+=now[tmp][1^xo];	
			cout<<ans<<endl;
		}
		else
		{
			int bb0=b[x[i][0]],bb1=b[x[i][1]];
			if(bb0==bb1)
			{
				cout<<ans<<endl;
				continue;
			}
			int sz1=v[bb0].size(),sz2=v[bb1].size();
			if(bb0==tmp)
				ans-=now[tmp][1^xo];
			else
				ans-=min(now[bb0][0],now[bb0][1]);
			if(bb1==tmp)
				ans-=now[tmp][1^xo];
			else
				ans-=min(now[bb1][0],now[bb1][1]);
			if(sz1<sz2)
			{
				int tc0,tc1;
				if(bb0==tmp)
					tc0=c[x[i][0]]^xo;
				else
					tc0=c[x[i][0]];
				if(bb1==tmp)
					tc1=c[x[i][1]]^xo;
				else
					tc1=c[x[i][1]];				
				if(tc0^tc1!=num[i])
				{
					for(int j=0;j<sz1;j++)
					{
						v[bb1].push_back(v[bb0][j]);
						if(bb0==tmp||bb1==tmp)
							c[v[bb0][j]]^=xo;
						b[v[bb0][j]]=b[bb1];
						now[bb1][c[v[bb0][j]]]++;
					}
					if(bb0==tmp)
						xo=0;
				}
				else
				{
					for(int j=0;j<sz1;j++)
					{
						v[bb1].push_back(v[bb0][j]);
						if(bb0==tmp||bb1==tmp)
							c[v[bb0][j]]^=xo^1;
						else
							c[v[bb0][j]]^=1;
						b[v[bb0][j]]=b[bb1];
						now[bb1][c[v[bb0][j]]]++;
					}
					if(bb0==tmp)
						xo=1;
				}
				if(bb0==tmp)
					tmp=bb1;
				if(bb1==tmp)
					ans+=now[tmp][1^xo];
				else
					ans+=min(now[bb1][0],now[bb1][1]);
			}
			else
			{
				int tc0,tc1;
				if(bb0==tmp)
					tc0=c[x[i][0]]^xo;
				else
					tc0=c[x[i][0]];
				if(bb1==tmp)
					tc1=c[x[i][1]]^xo;
				else
					tc1=c[x[i][1]];				
				if(tc0^tc1!=num[i])
				{
					for(int j=0;j<sz2;j++)
					{
						v[bb0].push_back(v[bb1][j]);
						if(bb0==tmp||bb1==tmp)
							c[v[bb1][j]]^=xo;
						b[v[bb1][j]]=b[bb0];
						now[bb0][c[v[bb1][j]]]++;
					}
					if(bb1==tmp)
						xo=0;
				}
				else
				{
					for(int j=0;j<sz2;j++)
					{
						v[bb0].push_back(v[bb1][j]);
						if(bb0==tmp||bb1==tmp)
							c[v[bb1][j]]^=xo^1;
						else
							c[v[bb1][j]]^=1;
						b[v[bb1][j]]=b[bb0];
						now[bb0][c[v[bb1][j]]]++;
					}
					if(bb1==tmp)
						xo=1;
				}
				if(bb1==tmp)
					tmp=bb0;
				if(bb0==tmp)
					ans+=now[tmp][1^xo];
				else
					ans+=min(now[bb0][0],now[bb0][1]);
			}
			cout<<ans<<endl;
		}
	}
			
}
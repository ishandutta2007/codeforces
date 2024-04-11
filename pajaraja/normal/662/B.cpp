#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> g[2][100001];
vector<int> z[4][100001];
vector<int> k[2];
bool vi[2][100001];
int a[2][100001];
int bfs(int s,int b,int t,int br)
{
	int r=0;
	queue<int> bfsq;
	vi[t][s]=true;
	a[t][s]=t;
	if(a[t][s]==1)
	{
		r++;
		z[2*b+t][br].push_back(s);
	}
	bfsq.push(s);
	int u,v;
	while(!bfsq.empty())
	{
		u=bfsq.front();
		bfsq.pop();
		for(int i=0;i<g[b][u].size();i++)
		{
			v=g[b][u][i];
			if(!vi[t][v])
			{
				bfsq.push(v);
				vi[t][v]=true;
				a[t][v]=1-a[t][u];
				if(a[t][v]==1)
				{
					r++;
					z[2*b+t][br].push_back(v);
				}
			}
			else
			{
				if(a[t][v]==a[t][u])
				{
					return -1;
				}
			}
		}
		for(int i=0;i<g[1-b][u].size();i++)
		{
			v=g[1-b][u][i];
			if(!vi[t][v])
			{
				bfsq.push(v);
				vi[t][v]=true;
				a[t][v]=a[t][u];
				if(a[t][v]==1)
				{
					z[2*b+t][br].push_back(v);
					r++;
				}
			}
			else
			{
				if(a[t][v]==1-a[t][u])
				{
					return -1;
				}
			}
		}
	}
	return r;
}
int main(int argc, char** argv) 
{
	int n,m,t1,t2,t3,l,d,br=0;
	char cz;
	bool c=true,p=true;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2>>cz;
		t3=((cz=='R')?0:1);
		g[t3][t1].push_back(t2);
		g[t3][t2].push_back(t1);	
	}
	fill(a[1],a[1]+100001,2);
	fill(a[0],a[0]+100001,2);
	fill(vi[1],vi[1]+100001,false);
	fill(vi[0],vi[0]+100001,false);
	for(int i=1;i<n;i++)
	{
		if(!vi[0][i])
		{
			l=bfs(i,1,1,br);
			d=bfs(i,1,0,br);
			if(l>d)
			{
				for(int j=0;j<d;j++)
				{
					k[1].push_back(z[2][br][j]);
				}
			}
			else
			{
				for(int j=0;j<l;j++)
		      	{
				    k[1].push_back(z[3][br][j]);
				}
			}
			br++;
			if(l==-1&&d==-1) p=false;
		}
	}
    fill(a[1],a[1]+100001,2);
	fill(a[0],a[0]+100001,2);
	fill(vi[1],vi[1]+100001,false);
	fill(vi[0],vi[0]+100001,false);
	br=0;
	for(int i=1;i<n;i++)
	{
		if(!vi[0][i])
		{
			l=bfs(i,0,1,br);
			d=bfs(i,0,0,br);
			if(l>d)
			{
				for(int j=0;j<d;j++)
				{
					k[0].push_back(z[0][br][j]);
				}
			}
			else
			{
				{
				for(int j=0;j<l;j++)
				{
					k[0].push_back(z[1][br][j]);
				}
			    }
			}
			br++;
			if(l==-1&&d==-1) c=false;
		}
	}
	int asd;
	if(!p&&!c)
	{
		cout<<-1;
	}
	else
	{
	
	    if((k[0].size()>k[1].size()&&p)||!c)
	    { 
		    asd=k[1].size();
		    cout<<asd<<endl;
		    for(int i=0;i<k[1].size();i++)
		    {
			    cout<<k[1][i]<<endl;
		    }
	    }
 	    else
	    {
		    asd=k[0].size();
		    cout<<asd<<endl;
		    for(int i=0;i<k[0].size();i++)
		    {
			    cout<<k[0][i]<<endl;
		    } 
	    }
	}
	return 0;
}
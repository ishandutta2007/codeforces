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
#define N 100010
using namespace std;
bool fd=false,book[N];
int n;
vector<int> vt[N];
vector<pair<int,int> > edge;
pair<int,int> st,fn,tw;
void print1()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		cout<<i<<endl;
	}
	return;
}
bool chain()
{
	int i,cnt0=0,cnt1=0;
	for(i=0;i<n;i++)
	{
		if(vt[i].size()>2)
		{
			return false;
		}
		if(vt[i].size()==2)
		{
			cnt1++;
		}
		else
		{
			cnt0++;
		}
	}
	if(cnt0==2)
	{
		return true;
	}
	return false;
}
void dfs(int x,int lst)
{
	book[x]=true;
	if(vt[x].size()==1&&lst!=-1)
	{
		fn=make_pair(lst,x);
		fd=true;
		return;
	}
	int i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
			if(fd)
			{
				return;
			}
		}
	}
	return;
}
int main(){
	int i,x,y;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		edge.push_back(make_pair(x,y));
	}
	if(chain())
	{
		print1();
		return 0;
	}
	memset(book,false,sizeof(book));
	for(i=0;i<n;i++)
	{
		if(vt[i].size()==1)
		{
			st=make_pair(i,vt[i][0]);
			dfs(i,-1);
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(!book[i])
		{
			tw=make_pair(i,vt[i][0]);
			break;
		}
	}
	x=3;
	for(i=0;i+1<n;i++)
	{
		if(edge[i]==st||(edge[i].F==st.S&&edge[i].S==st.F))
		{
			cout<<0<<endl;
		}
		else if(edge[i]==fn||(edge[i].F==fn.S&&edge[i].S==fn.F))
		{
			cout<<1<<endl;
		}
		else if(edge[i]==tw||(edge[i].F==tw.S&&edge[i].S==tw.F))
		{
			cout<<2<<endl;
		}
		else
		{
			cout<<x++<<endl;
		}
	}
	return 0;
}
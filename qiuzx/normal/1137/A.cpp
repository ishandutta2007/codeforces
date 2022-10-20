#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll read()
{
	char c;
	ll x=0;
	int f=1;
	c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			f=-f;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		x=(x<<3)+(x<<1)+(c^48);
	}
	return x*f;
}
int main(){
	vector<vector<int> > va;
	vector<vector<int> > vb;
	vector<vector<int> > v;
	vector<vector<int> > lo;
	vector<vector<int> > hi;
	ll n,m,i,j,a,sa,sb; 
	n=read();
	m=read();
	v.resize(1020);
	va.resize(1020);
	vb.resize(1020);
	lo.resize(1020);
	hi.resize(1020);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a=read();
			v[i].push_back(a);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			va[i].push_back(v[i][j]);
			vb[j].push_back(v[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		sort(va[i].begin(),va[i].end());
		va[i].erase(unique(va[i].begin(),va[i].end()),va[i].end());
	}
	for(i=0;i<m;i++)
	{
		sort(vb[i].begin(),vb[i].end());
		vb[i].erase(unique(vb[i].begin(),vb[i].end()),vb[i].end());
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			lo[i].push_back(max(lower_bound(va[i].begin(),va[i].end(),v[i][j])-va[i].begin(),lower_bound(vb[j].begin(),vb[j].end(),v[i][j])-vb[j].begin()));
			hi[i].push_back(max(va[i].size()-(lower_bound(va[i].begin(),va[i].end(),v[i][j])-va[i].begin())-1,vb[j].size()-(lower_bound(vb[j].begin(),vb[j].end(),v[i][j])-vb[j].begin())-1));
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<lo[i][j]+hi[i][j]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
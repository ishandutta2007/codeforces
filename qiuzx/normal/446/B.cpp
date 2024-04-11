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
#define N 1010
using namespace std;
ll n,m,k,p,a[N][N],ans=-INF127;
priority_queue<ll> row,col;
vector<ll> r,c;
int main(){
	ll i,j,sum;
	cin>>n>>m>>k>>p;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<m;j++)
		{
			sum+=a[i][j];
		}
		row.push(sum);
	}
	for(i=0;i<m;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=a[j][i];
		}
		col.push(sum);
	}
	r.push_back(0);
	c.push_back(0);
	for(i=0;i<k;i++)
	{
		r.push_back(r[r.size()-1]+row.top());
		c.push_back(c[c.size()-1]+col.top());
		sum=row.top();
		row.pop();
		row.push(sum-p*m);
		sum=col.top();
		col.pop();
		col.push(sum-p*n);
	}
	for(i=0;i<=k;i++)
	{
		ans=max(ans,r[i]+c[k-i]-i*(k-i)*p);
	}
	cout<<ans<<endl; 
	return 0;
}
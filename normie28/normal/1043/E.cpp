#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
long long n, m, k, cnt, i, j, a = 1e10, b = 0, c=0, x[300000],y[300000],diff[300000];
char mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	long long sum[300001],prex[300001],prey[300001];
vector<long long> aa,bb;
int cmp (long long a, long long b)
{
	return ((diff[a])<(diff[b]));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		aa.push_back(i);
		diff[i]=x[i]-y[i];
	}
	sort (aa.begin(),aa.end(),cmp);
	for (i=1;i<=n;i++)
	{
//		cout<<aa[i-1]<<endl;
		prex[i]=prex[i-1]+x[aa[i-1]];
		prey[i]=prey[i-1]+y[aa[i-1]];
	}
	for (i=0;i<n;i++)
	{
		sum[aa[i]]=y[aa[i]]*i+prex[i]+x[aa[i]]*(n-1-i)+prey[n]-prey[i+1];
	}
	for (i=0;i<m;i++)
	{
		cin>>a>>b; a--; b--;
		sum[a]-=min(x[a]+y[b],y[a]+x[b]);
		sum[b]-=min(x[a]+y[b],y[a]+x[b]);
	}
	for (i=0;i<n;i++) cout<<sum[i]<<' ';
}
//x[j]+y[i]<x[i]+y[j]
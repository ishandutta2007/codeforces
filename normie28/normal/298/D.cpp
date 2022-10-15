#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
int n, m, k, cnt, i, j, a = 1e10, b = 0, c=0, dp[201][201][201];
long long mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	long long sum[300001],prex[300001],prey[300001];
vector<int> aa,bb,cc;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (i=0;i<n;i++) {cin>>a; aa.push_back(a); cc.push_back(a);}
	for (i=0;i<m;i++) {cin>>a; bb.push_back(a); cc.push_back(a);}
	sort (aa.begin(),aa.end());
	sort (bb.begin(),bb.end());
	for (i=0;i<m+n;i++)
	{
		int cnta=aa.end()-lower_bound(aa.begin(),aa.end(),cc[i]);
		int cntb=bb.end()-lower_bound(bb.begin(),bb.end(),cc[i]);
		if (cnta>cntb) {cout<<"YES"; return 0;}
	}
	cout<<"NO";
}
//x[j]+y[i]<x[i]+y[j]
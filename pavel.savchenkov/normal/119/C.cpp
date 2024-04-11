#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory.h>
#define i64 long long
#define pb push_back
using namespace std;

i64 d[51][51][101];

struct task
{
	i64 a,b; int c; int ind;
	task() {};
	friend bool operator <(const task &x,const task &y) { return x.c <= y.c; }
};
int n,m,k;
task t[60];


int main() {
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++) { cin >> t[i].a >> t[i].b >> t[i].c; t[i].ind = i; }
	sort(t+1,t+m+1);

	
	for (int i=1; i<=n; i++)
		for (int j=1;j<=m;j++)
			for (int z=0; z<=t[j].b-t[j].a; z++) d[i][j][z] = -1;
	
	for (int i=1; i<=n; i++)
	 for (int j=1; j<=m; j++)
	  for (int z=0; z<=t[j].b-t[j].a; z++)
	  {
		if (i == 1) d[i][j][z] = t[j].a + z;
		if (d[i][j][z] == -1) continue;
		i64 now = t[j].a + z; 
		for (int next=j+1; next<=m; next++)
		{
			if (t[next].c == t[j].c) continue;
			if (now+k>=t[next].a && now+k<=t[next].b) 
				d[i+1][next][now+k-t[next].a] = max(d[i+1][next][now+k-t[next].a],d[i][j][z] + now + k); 
			
			if (now*k>=t[next].a && now*k<=t[next].b) 
				d[i+1][next][now*k-t[next].a] = max(d[i+1][next][now*k-t[next].a],d[i][j][z] + now * k); 
		}
	  }
	
	vector < pair < int, i64 > > res;
    int maxm = 1; int maxz = 0;
	
	for (int j=1;j<=m;j++)
		for (int z=0;z<=t[j].b-t[j].a;z++)
			if (d[n][j][z] > d[n][maxm][maxz]) { maxz = z; maxm = j; }
	
	if (d[n][maxm][maxz] <= 0) { cout << "NO" << endl; return 0; }

	res.pb(make_pair(t[maxm].ind,t[maxm].a+maxz));
			
	int ni = n-1; i64 now = t[maxm].a + maxz;
	int prevm = maxm;
	i64 maxres;
	
	while (ni > 0)
	{
		maxres = -1; maxz = -1; maxm = -1;
		for (int j=1;j<prevm;j++)
		 for (int z=0;z<=t[j].b-t[j].a;z++)
			if ( d[ni][j][z] > maxres && ( t[j].a+z==now-k || (t[j].a+z==now/k && now%k==0) ) )
			 { maxz = z; maxm = j; maxres = d[ni][j][z]; }
			 
		res.pb(make_pair(t[maxm].ind,t[maxm].a+maxz));
		now = t[maxm].a+maxz; ni--; prevm = maxm;
	}
	
	int sz = (int)res.size();
	
	cout << "YES" << endl;
	for (int i=sz-1;i>=0;i--)
		cout << res[i].first << " " << res[i].second << endl;
	return 0;
}
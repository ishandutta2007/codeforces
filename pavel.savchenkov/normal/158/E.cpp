//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define pb push_back
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define f first
#define s second
#define inf 2000000000
using namespace std;
int start[5000]; int len[5000];
int d[4100][4100];
int n; int k;

int go()
{
	int ans = 0;
	d[0][1] = 0;
	
	forn(i,n)
	 for (int j=0; j<=min(k,i+1); j++)
	 {
		if (j == 0) 
		{
			if (i == 0) d[i][j] = start[i] + len[i] - 1; else 
				if (d[i-1][j] >= start[i])  d[i][j] = min(d[i][j],d[i-1][j] + len[i]); 
			     else d[i][j] = min(d[i][j],start[i] + len[i] - 1); 
		}
		// d[i][j] - is done
		ans = max(ans,start[i + 1] - d[i][j] - 1);
		if (i == n) continue;
		if (start[i+1] <= d[i][j]) d[i+1][j] = min(d[i+1][j],d[i][j] + len[i+1]); 
		 else d[i+1][j] = min(d[i+1][j],start[i+1] + len[i+1] - 1);
		if (j < k) 
			d[i+1][j+1] = min(d[i+1][j+1],d[i][j]);
	 }
	 
	return ans;
}

int main() {
  //freopen("input.txt","r",stdin);
  scanf("%d%d",&n,&k);
  for (int i=1;i<=n;i++) scanf("%d%d",&start[i],&len[i]);
  start[0] = 0; len[0] = 1; start[n+1] = 86401; len[n+1] = 1; n++;
  forn(i,4010) forn(j,4100) d[i][j] = inf;
  
  
  cout << go() << endl;
  return 0;
}
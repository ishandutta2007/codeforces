//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#define pb push_back
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; scanf("%d",&n);
   vector < int > gd[n+1];
   
   int g[n+1];
   for (int i=0;i<n;i++)
	   for (int j=0;j<n;j++)
	   {
		   int v; scanf("%d",&v); if (v!=i+1) gd[i].pb(v);
	   }
	
   for (int i=0;i<n;i++)
	   scanf("%d",&g[i]);
   
	/*for (int i=0;i<n;i++)
	{
		for (int j=0;j<n-1;j++)
			cout << gd[i][j] << " ";
		cout << endl;
	}*/
	
   int d[n+1];
   for (int i=0;i<n;i++) d[i] = inf;
   
   for (int step=1; step<=n;step++)
   {
	
	 for (int i=0;i<n;i++)
	 {
	       
	        bool can[n+1];
	        for (int j=1;j<=n;j++) can[j] = false;
			int res = -1;
			for (int k=0;k<n;k++)
		      if (g[k] <= step && g[k]!=i+1) { res = g[k]; break; } 
			  
			if (res == -1) continue;
			  
	        for (int j=0;j<n-1;j++)
				if (gd[i][j] == res) { res = j; break; }
			if (d[i]>res) d[i] = res; 
	 }
	 
	// for (int i=0; i<n; i++)
	 // printf("%d ",d[i]); cout << endl;
   }
   

  for (int i=0; i<n; i++)
  {
    cout << gd[i][d[i]] << " ";
  }
   return 0;
}
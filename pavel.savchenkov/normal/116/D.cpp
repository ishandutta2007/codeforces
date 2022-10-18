#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n,m;
	scanf("%d %d\n",&n,&m);
	char g[n+1][m+1];
	int l[n+1];
	int r[n+1];
	bool has[n+1];
	for (int i=1;i<=n;i++) {r[i]=-1;l[i]=-1;has[i]=false;}
	for (int i=1;i<=n;i++) {
		scanf("%s",&g[i]); 
		for (int j=0;j<m;j++)
			{ if (g[i][j]=='W'&l[i]==-1) l[i]=j;
              if (g[i][j]=='W') {r[i]=j;has[i]=true;}
			}
	}
	int last=-1;		
	for (int i=1;i<=n;i++) {if (l[i]==-1) l[i]=10000;if (has[i]) last=i;}	

	l[n+1]=10000; r[n+1]=-1;
	int res=0; int k=0;		
	for (int i=1;i<=n;i++)
		if (i<=last) {if (i%2==1) {res+=max(max(r[i],k),r[i+1])-k+1;k=max(max(r[i],k),r[i+1]);} else
		   {res+=k-min(min(l[i],k),l[i+1])+1; k=min(min(k,l[i]),l[i+1]);}}
	if (res>0) res--;	
    printf("%d",res);		   
	return 0;
}
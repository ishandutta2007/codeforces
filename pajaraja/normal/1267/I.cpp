#include <bits/stdc++.h>
#define MAXN 207
using namespace std;
int p[MAXN][MAXN],pr[MAXN];
char c[20];
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		for(int i=1;i<=2*n;i++) for(int j=1;j<=2*n;j++) p[i][j]=0;
		vector<int> sl;
		for(int i=1;i<=n;i++) {pr[i]=i+n; pr[n+i]=i;}
		for(int i=1;i<=n;i++)
		{
			printf("? %d %d\n",i,n+i);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='<') sl.push_back(i);
			else sl.push_back(n+i);
		}
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
		{
			printf("? %d %d\n",sl[i],sl[j]);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='<') {p[sl[i]][sl[j]]=-1; p[sl[j]][sl[i]]=1;}
			else {p[sl[i]][sl[j]]=1; p[sl[j]][sl[i]]=-1;}
		}
		int x;
		for(int i=0;i<n;i++) 
		{
			bool rd=true;
			for(int j=0;j<n;j++) if(p[sl[i]][sl[j]]==-1) rd=false;
			if(rd) x=sl[i];
		}
		x=pr[x];
		vector<int> g; for(int i=0;i<n;i++) if(pr[sl[i]]!=x) g.push_back(pr[sl[i]]); 
		for(int i=0;i<n-1;i++) for(int j=i+1;j<n-1;j++)
		{
			if(g[i]==x || g[j]==x) continue;
			printf("? %d %d\n",g[i],g[j]);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='<') {p[g[i]][g[j]]=-1; p[g[j]][g[i]]=1;}
			else {p[g[i]][g[j]]=1; p[g[j]][g[i]]=-1;}
		}
		int y;
		for(int i=0;i<n-1;i++) 
		{
			bool rd=true;
			for(int j=0;j<n-1;j++) if(p[g[i]][g[j]]==-1) rd=false;
			if(rd) y=g[i];
		}
		for(int i=1;i<=2*n;i++) for(int j=i+1;j<=2*n;j++)
		{
			if(i==x || j==x || i==y || j==y || p[i][j]) continue;
			printf("? %d %d\n",i,j);
			fflush(stdout);
			scanf("%s",c);
			p[i][j]=1; p[j][i]=1;
		}
		printf("!\n");
		fflush(stdout);
	}
}
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m; vector <int> q(3); 
	scanf("%d%d",&n,&m); int d[n+1][m+1];
	int sumstb[m+1]; int sumstr[n+1]; sumstr[0]=0; sumstb[0]=0;
	for (int i=1;i<=n;i++)
	{   int s=0;
		for (int j=1;j<=m;j++)
			{scanf("%d",&d[i][j]);s+=d[i][j];}
		sumstr[i]=sumstr[i-1]+s;	
	}	
	scanf("%d%d%d",&q[0],&q[1],&q[2]);
	sort(q.begin(),q.end());
	for (int j=1;j<=m;j++)
	{   int s=0;
		for (int i=1;i<=n;i++)
			s+=d[i][j];
		sumstb[j]=sumstb[j-1]+s;
	}
	
	vector <int> g(3);
	int x,y,res=0;;
	for (x=1;x<=m-2;x++)
		for (y=x+1;y<=m-1;y++)
				{g[0]=sumstb[x];g[1]=sumstb[y]-sumstb[x]; g[2]=sumstb[m]-sumstb[y]; sort(g.begin(),g.end());
                  if (q[0]==g[0]&q[1]==g[1]&q[2]==g[2]) res++;}
			
	for (x=1;x<=n-2;x++)
		for (y=x+1;y<=n-1;y++)
				{g[0]=sumstr[x];g[1]=sumstr[y]-sumstr[x]; g[2]=sumstr[n]-sumstr[y]; sort(g.begin(),g.end());
                  if (q[0]==g[0]&q[1]==g[1]&q[2]==g[2]) res++;}
	
	printf("%d",res);
	return 0;
}
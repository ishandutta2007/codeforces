#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
vector <int> p;
int n,k;

void gen(int l,int a) {
	if (l>k) return;
	if (l==k) p.push_back(a);
	vector <bool> has(k+1,false);
	int a1=a;
	while (a1>0) {
		has[a1%10]=true; a1/=10;
	}
	for (int i=1;i<=k;i++)
		if (!has[i]) gen(l+1,a*10+i);
}

int main() {
   //freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   scanf("%d%d\n",&n,&k);
   for (int i=1;i<=k;i++) gen(1,i);
   char g[n+1][k+1];
   for (int i=1;i<=n;i++)
	   scanf("%s\n",g[i]);

   int st[k+1];
   st[0]=1; 
   for (int i=1;i<=k;i++)
	st[i]=st[i-1]*10;
   int ans=1000000000;
   //for (int i=1;i<=n;i++) printf("%s\n",g[i]);
   
   for (int i=0;i<(int)p.size();i++)
   { int max=-1;int min=100009999;
	  for (int j=1;j<=n;j++)
	  {
		  int q=p[i]; int res=0; int d=0; 
		  while (q>0) 
		  {
			  res+=(g[j][q%10-1]-'0')*st[d];d++;q/=10;
		  }
		if (res>max) max=res;
		if (res<min) min=res;
	  }
	  if (max-min<ans) ans=max-min;
   }
	   
   //for (int i=0;i<(int)p.size();i++)
	//   printf("%d\n",p[i]);
   printf("%d",ans);
   return 0;
}
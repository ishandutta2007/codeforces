#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const double e=0.0000009;
int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; double w; int m;
   scanf("%d %lf %d",&n,&w,&m);
   vector <double> b(n+1,w);
   vector <double> k(m+1,0);
   double x=(double)n*w/m;
   if (w/x>2) {printf("NO");return 0;}
   int eb=1; int i=1;
   vector < pair < int , double > > res[m+1];
   bool was[n+1][m+1];
   for (int i=1;i<=n;i++)
	    for (int j=1;j<=m;j++) was[i][j]=false;
   
   
   while (i<m+1) 
   { if (x-k[i]<=b[eb]) {b[eb]=b[eb]-x+k[i];res[i].push_back(make_pair(eb,x-k[i])); was[eb][i]=true; k[i]=x;  if (b[eb]<=0+e) eb++;}
	   else {k[i]+=b[eb]; res[i].push_back(make_pair(eb,b[eb]));was[eb][i]=true; b[eb]=0; eb++; }
	 if (k[i]>=x-e) i++;  
   }
   
      for (int i=1;i<=n;i++) {
		  int d=0;
        for (int j=1;j<=m;j++)
			if (was[i][j]) d++;
		if (d>2) {printf("NO");return 0;}
   } 
	printf("YES\n");  
   for (int i=1;i<=m;i++) {
	    for (int j=0;j<(int)res[i].size();j++)
			 printf("%d %.6lf ",res[i][j].first,res[i][j].second);
		printf("\n");
   }
    return 0;
}
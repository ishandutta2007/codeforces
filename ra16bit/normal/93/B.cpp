#include <cstdio>
#include <vector>
using namespace std;
int n,w,m,i,j;
double x,y,eps=1e-8;
vector <int> r[55];
vector <double> c[55];
int main() {
  scanf("%d%d%d",&n,&w,&m);
  x=double(n*w)/m;
  if (w>2*x+eps) { puts("NO"); return 0; }
  for (i=j=0; i<n; i++) {
    y+=w;
	r[j].push_back(i+1);
    if (y>x-eps) {
	  y-=x;
	  c[j++].push_back(w-y+eps);
	  if (y>eps) {
	    if (y>x+eps) { puts("NO"); return 0; }
	    r[j].push_back(i+1);
	    c[j].push_back(y);
		if (y>x-eps) { j++; y=0; }
	  }
	} else c[j].push_back(w);
  }
  puts("YES");
  for (i=0; i<m; i++) {
    for (j=0; j<r[i].size(); j++) {
	  if (j) putchar(' ');
      printf("%d %.8lf",r[i][j],c[i][j]);
	}
	puts("");
  }
  return 0;
}
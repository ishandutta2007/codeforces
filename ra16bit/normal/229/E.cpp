#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,j,k,n,m,M,cur,mids,x,y,good[1010],mid[1010];
long double c[1010][1010],f[1010][1010],cnt[1010][1010];
vector <int> all,ins[1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d",&x);
	while (x--) {
	  scanf("%d",&y); y*=2;
	  ins[i].push_back(y);
	  all.push_back(y);
	}
  }
  if (n==all.size()) { puts("1"); return 0; }
  sort(all.rbegin(),all.rend());
  M=(1LL*all[n-1]+all[n])/2;
  for (i=0; i<m; i++) {
    cur=ins[i].size();
    for (j=0; j<cur; j++) {
      if (ins[i][j]>M) good[i]++;
	  if (ins[i][j]==M) mid[i]++;
	}
	c[i][0]=1.0;
	for (j=max(good[i],cur-good[i])+1, k=1; j<=cur; j++, k++) c[i][0]*=double(k)/double(j);
	for (j=1; j<=mid[i]; j++) {
	  c[i][j]=c[i][j-1]/double(j);
	  c[i][j]*=mid[i]-j+1.0;
	  c[i][j]/=cur-good[i]-j+1.0;
	  c[i][j]*=good[i]+j;
	}
	mids+=mid[i];
	//printf("g %d m %d %.5lf %.5lf\n",good[i],mid[i],double(c[i][0]),double(c[i][1]));
	n-=good[i];
  }
  f[0][0]=1.0;
  cnt[0][0]=1.0;
  for (i=0; i<=m; i++) for (j=0; j<=n; j++) for (k=0; k<=mid[i]; k++) {
    f[i+1][j+k]+=f[i][j]*c[i][k];
	cnt[i+1][j+k]+=cnt[i][j];
  }
//  printf("%d %d = %.5lf\n",i,j,double(f[i][j]));
//  printf("%d\n",n);
  printf("%.12lf\n",double(f[m][n]/cnt[m][n]));
  return 0;
}
#include <cstdio>
#include <vector>
using namespace std;
int n,q,i,ea,eb,ec[100100],s[100100];
vector<pair<int,int> > g[100100];
double p[100100],all,r;
double two(double x) {
  return 0.5*x*(x-1.0);
}
void dfs(int i, int pr) {
  s[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j].first;
    if (k==pr) continue;
    dfs(k,i);
    p[g[i][j].second]=s[k]*two(n-s[k])+(n-s[k])*two(s[k]);
    s[i]+=s[k];
  }
}
int main() {
  scanf("%d",&n);
  all=n; all*=n-1; all*=n-2; all/=6;
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&ea,&eb,&ec[i]);
    g[ea].push_back(make_pair(eb,i));
    g[eb].push_back(make_pair(ea,i));
  }
  dfs(1,0);
  for (i=1; i<n; i++) r+=p[i]*ec[i];
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&i,&ea);
    r+=p[i]*(ea-ec[i]);
    ec[i]=ea;
    printf("%.11lf\n",2.0*r/all);
  }
  return 0;
}
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int num,n,m,i,j,r,p[100100],e[100100],o[100100],b[300300];
char z[100100],s[300300];
vector <int> g[300300];
vector <char> c[300300];
void dfs(int i, int pos) {
  if (pos==m) { r++; pos=b[m-1]; }
  for (int j=0; j<g[i].size(); j++) {
    int npos=pos;
    for (; npos>0 && c[i][j]!=s[npos]; npos=b[npos-1]);
	if (c[i][j]==s[npos]) npos++;
	dfs(g[i][j],npos);
  }
}
int main() {
  scanf("%d",&num);
  o[1]=n=1;
  for (i=2; i<=num; i++) {
    scanf("%d",&p[i]);
	scanf("%s",s);
	m=strlen(s);
	e[i]=++n; z[i]=s[0];
	for (j=1; j<m; j++) {
	  g[n].push_back(n+1);
	  c[n++].push_back(s[j]);
	}
	o[i]=n;
  }
  for (i=2; i<=num; i++) {
    g[o[p[i]]].push_back(e[i]);
	c[o[p[i]]].push_back(z[i]);
  }
  scanf("%s",s);
  m=strlen(s);
  for (i=1; i<m; i++) {
    for (b[i]=b[i-1]; b[i]>0 && s[i]!=s[b[i]]; b[i]=b[b[i]-1]);
	if (s[i]==s[b[i]]) b[i]++;
  }
  dfs(1,0);
  printf("%d\n",r);
  return 0;
}
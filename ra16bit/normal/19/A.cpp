#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int i,j,ii,n,nn,k[200],a,b,x,y,c[200],d[200],e[200];
char ss[200],tt[200];
string s,t,st[200];
vector <string> r;
map <string, int> m;
bool cmp(int i, int j) {
  return (c[i]>c[j] || (c[i]==c[j] && (d[i]>d[j] || (d[i]==d[j] && e[i]>e[j]))));
}
int main() {
  scanf("%d",&n); gets(ss);
  for (i=0; i<n; i++) {
    gets(ss); st[i+1]=s=ss;
    m[s]=i+1; k[i]=i+1;
  }
  for (i=0; i<(n*(n-1))/2; i++) {
    scanf("%s %d:%d",&ss,&a,&b);
    nn=strlen(ss);
    for (j=0; j<nn; j++) if (ss[j]=='-') {
      s=""; t="";
      for (ii=0; ii<j; ii++) s+=ss[ii];
      for (ii=j+1; ii<nn; ii++) t+=ss[ii];
      break;
    }
    x=m[s]; y=m[t];
    if (a==b) {
      c[x]++; c[y]++;
    } else if (a>b) c[x]+=3; else c[y]+=3;
    d[x]+=a-b; d[y]+=b-a;
    e[x]+=a;   e[y]+=b;
  }
  sort(k,k+n,cmp);
  for (i=0; i<n/2; i++) r.push_back(st[k[i]]);
  sort(r.begin(),r.end());
  for (i=0; i<r.size(); i++) puts(r[i].c_str());
  return 0;
}
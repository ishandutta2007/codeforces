#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int MX=1000100;
int i,k,n,num,cur,m,r,a[MX],p[MX],z[222];
bool just,end,q;
char s[MX];
vector <int> g[MX];
string cs;
map <string, int> M;
void dfs(int i, int pos) {
  if (a[i]==z[pos]) {
    if (pos==k-1) r++; else pos++;
  }
  for (int j=0; j<g[i].size(); j++) dfs(g[i][j],pos);
}
int main() {
  gets(s);
  for (i=0; s[i]; i++) if (s[i]=='<') {
    cs="";
    end=false;
    just=true;
  } else {
    if (s[i]=='>') {
      if (end) cur=p[cur]; else {
        g[cur].push_back(++n);
        p[n]=cur;
        a[n]=M[cs];
        if (a[n]==0) a[n]=M[cs]=++num;
        cur=n;
      }
    } else if (s[i]=='/') {
      if (just) end=true; else {
        g[cur].push_back(++n);
        p[n]=cur;
        a[n]=M[cs];
        if (a[n]==0) a[n]=M[cs]=++num;
        i++;
      }
    } else cs=cs+s[i];
    just=false;
  }
  scanf("%d\n",&m);
  while (m--) {
    gets(s);
    q=true; cs="";
    for (i=k=0; s[i]; i++) if (s[i]==' ') {
      z[k]=M[cs];
      if (z[k]==0) { q=false; break; } else k++;
      cs="";
    } else cs=cs+s[i];
    if (q) {
      z[k]=M[cs];
      if (z[k]==0) q=false; else k++;
    }
    r=0;
    if (q) dfs(0,0);
    printf("%d\n",r);
  }
  return 0;
}
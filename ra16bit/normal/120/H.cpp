#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;
int i,j,x,y,z,n,m,Mit,mmc,cur,res,R[202],u[202],b[1000100];
string s[202],r[202],sj,sx,sy,sz,mr[1000100];
set <string>::iterator it;
set <string> st[202];
map <string, int> M,mm;
vector <int> g[202];
bool q;
bool cmp(int i, int j) { return s[i].length()<s[j].length(); }
bool dfs(int i) {
  u[i]=z;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (b[k]==-1 || (u[b[k]]!=z && dfs(b[k]))) {
      b[k]=i; R[i]=k;
      return true;
    }
  }
  return false;
}
void minusone() {
  int i,j;
  for (i=0; i<n; i++) for (it=st[i].begin(); it!=st[i].end(); it++) {
    Mit=mm[*it];
    if (Mit==0) { mm[*it]=Mit=++mmc; mr[mmc]=*it; }
    g[i].push_back(Mit);
  }
  memset(b,255,sizeof(b));
  memset(R,255,sizeof(R));
  for (i=0; i<n; i++) if (r[i]!="") { j=mm[r[i]]; R[i]=j; b[j]=i; }
  for (z=i=0; i<n; i++) if (R[i]==-1) {
    ++z;
    if (!dfs(i)) { cout<<"-1\n"; return; }
  }
  for (i=0; i<n; i++) cout<<mr[R[i]]<<'\n';
}
int main() {
  srand(time(0));
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin>>n;
  for (i=0; i<n; i++) {
    cin>>s[i];
    m=s[i].length();
    for (j=0; j<m; j++) {
      sj=""; sj+=s[i][j];
      st[i].insert(sj);
      for (x=j+1; x<m; x++) {
        sx=sj+s[i][x];
        st[i].insert(sx);
        for (y=x+1; y<m; y++) {
          sy=sx+s[i][y];
          st[i].insert(sy);
          for (z=y+1; z<m; z++) {
            sz=sy+s[i][z];
            st[i].insert(sz);
          }
        }
      }
    }
    for (it=st[i].begin(); it!=st[i].end(); it++) M[*it]++;
  }
  for (x=0; x<n; x++) {
    res=444;
    for (y=0; y<n; y++) if (r[y]=="") {
      for (cur=0, it=st[y].begin(); it!=st[y].end(); it++) if (M[*it]>0) {
        if (++cur>=res) break;
        sj=*it;
      }
      if (cur==0) { minusone(); return 0; }
      if (cur==1) {
        q=true;
        r[y]=sj;
        M[sj]=0;
        for (it=st[y].begin(); it!=st[y].end(); it++) M[*it]--;
        break;
      }
      cur=444;
      for (it=st[y].begin(); it!=st[y].end(); it++) {
        Mit=M[*it];
        if (Mit>0 && Mit<cur || (Mit==cur && (rand()&1))) { r[y]=*it; cur=Mit; }
      }
      if (cur==444) { minusone(); return 0; }
      M[r[y]]=0;
      for (it=st[y].begin(); it!=st[y].end(); it++) M[*it]--;
    }
  }
  for (i=0; i<n; i++) cout<<r[i]<<'\n';
  return 0;
}
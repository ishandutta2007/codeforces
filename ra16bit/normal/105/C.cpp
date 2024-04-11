#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int i,j,k,e,l,n,m,t,xx,K[3];
char ss[22],tt[22];
string st;
vector <string> s[3],p[3];
vector <int> em,a[3],x[3],y[3],z[3],q[3],sr[3],su[3],o,v,cur,curv;
vector <vector <int> > b[3],c[3];
bool cmp(int x, int y) { return q[j][x]>q[j][y]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",ss);
    scanf("%s",tt);
    if (tt[0]=='w') t=0; else if (tt[0]=='a') t=1; else t=2;
    s[t].push_back(ss);
    scanf("%d",&xx); x[t].push_back(xx);
    scanf("%d",&xx); y[t].push_back(xx);
    scanf("%d",&xx); z[t].push_back(xx);
    scanf("%d",&xx); a[t].push_back(xx);
    b[t].push_back(em); c[t].push_back(em);
  }
  scanf("%d",&m);
  while (m--) {
    scanf("%s",ss);
    scanf("%s",tt);
    if (tt[0]=='g') t=0; else if (tt[0]=='s') t=1; else t=2;
    p[t].push_back(ss); scanf("%d",&xx);
    q[t].push_back(xx); scanf("%s",ss); st=ss;
    sr[t].push_back(q[t].size()-1);
    su[t].push_back(0);
    for (j=0; j<3; j++) {
      for (i=0; i<s[j].size(); i++) if (s[j][i]==st) break;
      if (i<s[j].size()) {
        b[j][i].push_back(t);
        c[j][i].push_back(q[t].size()-1);
        break;
      }
    }
  }
  for (j=0; j<3; j++) {
    for (i=0; i<s[j].size(); i++) if (b[j][i].size()<a[j][i]) break;
    if (i<s[j].size()) break;
  }
  if (j<3) {
    for (j=0; j<3; j++) {
      if (sr[j].size()>0) {
        sort(sr[j].begin(),sr[j].end(),cmp);
        su[j][0]=q[j][sr[j][0]];
        for (i=1; i<sr[j].size(); i++) su[j][i]=su[j][i-1]+q[j][sr[j][i]];
      }
      for (k=e=i=0; i<s[j].size(); i++) {
        if (j==0) xx=x[j][i]; else if (j==1) xx=y[j][i]; else xx=z[j][i];
        if (su[j].size()>0) {
          if (a[j][i]<su[j].size()) xx+=su[j][a[j][i]-1]; else xx+=su[j][su[j].size()-1];
        }
        if (xx>e) { e=xx; k=i; }
      }
      K[j]=k;
      for (i=a[j][k]; i<sr[j].size(); i++) {
        o.push_back(j);
        v.push_back(sr[j][i]);
      }
    }
    for (xx=j=0; j<3; j++) {
      cur.clear(); curv.clear();
      for (i=0; i<sr[j].size() && i<a[j][K[j]]; i++) {
        cur.push_back(j);
        curv.push_back(sr[j][i]);
      }
      for (; i<a[j][K[j]] && xx<o.size(); i++, xx++) {
        cur.push_back(o[xx]);
        curv.push_back(v[xx]);
      }
      printf("%s %d",s[j][K[j]].c_str(),cur.size());
      for (i=0; i<cur.size(); i++) printf(" %s",p[cur[i]][curv[i]].c_str());
      puts("");
    }
  } else for (j=0; j<3; j++) {
    for (k=e=i=0; i<s[j].size(); i++) {
      if (j==0) xx=x[j][i]; else if (j==1) xx=y[j][i]; else xx=z[j][i];
      for (l=0; l<c[j][i].size(); l++) if (b[j][i][l]==j) xx+=q[b[j][i][l]][c[j][i][l]];
      if (xx>e) { e=xx; k=i; }
    }
    printf("%s %d",s[j][k].c_str(),c[j][k].size());
    for (l=0; l<c[j][k].size(); l++) printf(" %s",p[b[j][k][l]][c[j][k][l]].c_str());
    puts("");
  }
  return 0;
}
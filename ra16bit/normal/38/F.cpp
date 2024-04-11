#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;
const string S[2]={"First\n","Second\n"};
int i,j,p,ii,jj,nn,pp,k,e,n,A[999999],B[999999],x[999999],y[999999],z[999999];
map <string, int> m;
string s,s1;
vector <int> g[999999];
bool u[999999],C[999999];
void solve(int i) {
  if (u[i]) return;
  int j,k,a,b,e;
  bool c;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    if (y[k]) {
      solve(k);
      a=A[k]; b=B[k]+x[k]+y[k]; c=!C[k];
      if ((int(c)>int(C[i])) || (c==C[i] && (b>A[i] || (b==A[i] && a<B[i])))) {
        C[i]=c; A[i]=b; B[i]=a;
      }
    }
  }
  u[i]=true;
}
int main() {
  cin>>n; s="#";
  for (e=0; e<26; e++) {
    s[0]=char('a'+e); m[s]=e+1;
    x[e+1]=(e+1)*(e+1);
    g[0].push_back(e+1);
  }
  for (i=0; i<n; i++) {
    cin>>s; nn=s.length();
    for (j=0; j<nn; j++) {
      s1=s.substr(j,1); k=m[s1];
      if (z[k]!=i+1) { y[k]++; z[k]=i+1; }
    }
    for (p=2; p<=nn; p++) for (j=0; j+p<=nn; j++)  {
      s1=s.substr(j,p); k=m[s1];
      if (k==0) {
        m[s1]=k=++e; pp=0;
        for (ii=jj=j; ii<j+p; ii++) {
          pp+=s[ii]-'a'+1;
          if (s[ii]>s[jj]) jj=ii;
        }
        x[k]=pp*int(s[jj]-'a'+1);
      }
      if (z[k]!=i+1) { y[k]++; z[k]=i+1; }
      g[m[s.substr(j,p-1)]].push_back(k);
      g[m[s.substr(j+1,p-1)]].push_back(k);
    }
  }
  solve(0);
  cout<<S[1-int(C[0])]<<A[0]<<' '<<B[0]<<'\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MX=10100,MB=1000100;
int n,m,i,j,k,cur,num,g[MX],b[MB][26];
bool a[MB],f[MX];
char s[MX],t[MX];
vector<string> r;
string st,z;
map<string,string> w;
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&m);
  while (m--) {
    scanf("%s",t);
    j=strlen(t);
    st=t; z="";
    for (i=j-1, k=0; i>=0; i--) {
      if (t[i]>='a' && t[i]<='z') cur=t[i]-'a'; else cur=t[i]-'A';
      z+=cur+'a';
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
    a[k]=true;
    reverse(z.begin(),z.end());
    w[z]=st;
  }
  f[0]=true;
  for (i=0; i<n; i++) if (f[i]) {
    for (j=i, k=0; j<n; j++) {
      cur=s[j]-'a';
      if (b[k][cur]==0) break;
      k=b[k][cur];
      if (a[k]) { f[j+1]=true; g[j+1]=i; }
    }
  }
  for (i=n; i>0; i=g[i]) {
    st="";
    for (j=i-1; j>=g[i]; j--) st+=s[j];
    r.push_back(st);
  }
  for (i=int(r.size())-1; i>=0; i--) printf("%s%c",w[r[i]].c_str(),i?' ':'\n');
  return 0;
}
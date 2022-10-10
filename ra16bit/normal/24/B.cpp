#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int o[10]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int tt,t,n,i,j,z,k,e,a[77],v[77][55];
char st[77];
string s,b[77];
map <string, int> m;
int main() {
  scanf("%d",&tt);
  for (t=0; t<tt; t++) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%s",&st);
      s=st; e=m[s];
      if (e==0) { e=++k; b[e]=s; m[s]=e; }
      if (i<10) a[e]+=o[i];
      v[e][i]++;
    }
  }
  for (i=j=1; i<=k; i++) {
    if (a[i]!=a[j]) {
      if (a[i]>a[j]) j=i;
      continue;
    }
    for (z=0; z<55; z++) if (v[i][z]!=v[j][z]) {
      if (v[i][z]>v[j][z]) j=i;
      break;
    }
  }
  puts(b[j].c_str());
  for (i=j=1; i<=k; i++) {
    if (v[i][0]!=v[j][0]) {
      if (v[i][0]>v[j][0]) j=i;
      continue;
    }
    if (a[i]!=a[j]) {
      if (a[i]>a[j]) j=i;
      continue;
    }
    for (z=1; z<55; z++) if (v[i][z]!=v[j][z]) {
      if (v[i][z]>v[j][z]) j=i;
      break;
    }
  }
  puts(b[j].c_str());
  return 0;
}
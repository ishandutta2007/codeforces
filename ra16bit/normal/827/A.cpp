#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,x,mx,e,w;
vector<int> v[1001000];
char r[2002000],st[1001000];
string s[1001000];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s[i]=st;
    scanf("%d",&k);
    for (j=0; j<k; j++) {
      scanf("%d",&x);
      mx=max(x,mx);
      v[x-1].push_back(i);
    }
  }
  for (i=k=0; i<mx; i++) {
    for (j=0; j<v[i].size(); j++) {
      w=v[i][j];
      for (e=k-i; e<s[w].length(); e++, k++) r[i+e]=s[w][e];
    }
    if (i==k) { r[i]='a'; k++; }
  }
  puts(r);
  return 0;
}
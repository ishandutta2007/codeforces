#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;


typedef long long LL;
int n, m;
vector<int>G[128];
int len0[128], len1[128];
double next[128], prev[128];

void func(int s, int t, double ne[], int l[]) {
  l[s]=0;
  ne[s]=1;
  queue<int>qu;
  qu.push(s);
  for (;!qu.empty();) {
    int e=qu.front(); qu.pop();
    for (int i=0; i<(int)G[e].size(); i++) {
      int f=G[e][i];
      if (l[f]>l[e]+1) {
	l[f]=l[e]+1;
	qu.push(f);
	ne[f]=ne[e];
      } else if (l[f]==l[e]+1) {
	ne[f]+=ne[e];
      }
    }
  }
}

int main(){
  cin>>n>>m;
  for (int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  memset(len0, 0x3f, sizeof len0);
  func(0, n-1, next, len0);
  memset(len1, 0x3f, sizeof len1);
  func(n-1, 0, prev, len1);
  int l=len1[0];
  double ma=0;
  for (int i=0; i<n; i++) {
    if (len0[i]+len1[i]==l) {
      double d=next[i]*prev[i]/prev[0];
      if (i!=0 && i!=n-1) d*=2;
      ma=max(ma, d);
    }
  }
  
  printf("%.16f\n", ma);
  return 0;
}
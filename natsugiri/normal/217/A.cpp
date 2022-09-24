#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


int U[128];

void init() {
  for (int i=0; i<128; i++) U[i]=i;
}
int root(int n) {
  if (U[n]==n) return n;
  return U[n]=root(U[n]);
}
int link(int x, int y) {
  int p, q;
  p=root(x);
  q=root(y);
  return U[p]=U[q]=U[x]=U[y]=min(p,q);
}


int n, x[128], y[128];
vector<pair<int,int> >v;

int main(){
  init();
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d%d", x+i, y+i);
  
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (x[i]==x[j] || y[i]==y[j]) {
	v.push_back(make_pair(i,j));
      }
    }
  }
  
  random_shuffle(v.begin(), v.end());
  for (int i=0; i<(int)v.size(); i++) {
    link(v[i].first, v[i].second);
  }

  int ans=-1;
  for (int i=0; i<n; i++) if (U[i]==i) ans++;
  printf("%d\n", ans);
  
  return 0;
}
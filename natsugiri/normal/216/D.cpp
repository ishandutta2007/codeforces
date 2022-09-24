#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int>V[1024];
const int INF=0x3f3f3f3f;

int main(){

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int k;
    scanf("%d", &k);
    for (int j=0; j<k; j++) {
      int p;
      scanf("%d", &p);
      V[i].push_back(p);
    }
    V[i].push_back(INF);
    sort(V[i].begin(), V[i].end());
  }

  int ans=0;
  for (int i=0; i<n; i++) {
    int x=(i+n-1)%n, y=(i+1)%n;
    for (int j=1; j<(int)V[i].size()-1; j++) {
      int p, q, r, s;
      p=lower_bound(V[x].begin(), V[x].end(), V[i][j-1])-V[x].begin();
      q=upper_bound(V[x].begin(), V[x].end(), V[i][j])-V[x].begin();
      r=lower_bound(V[y].begin(), V[y].end(), V[i][j-1])-V[y].begin();
      s=upper_bound(V[y].begin(), V[y].end(), V[i][j])-V[y].begin();
      if (q-p!=s-r) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
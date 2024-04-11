#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int a[55], b[55];
vector<int>v;
int main(){

  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a+i);
  scanf("%d", &m);
  for (int i=0; i<m; i++) scanf("%d", b+i);

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (b[j]%a[i]==0) v.push_back(b[j]/a[i]);
    }
  }
  sort(v.begin(), v.end());
  int ans=0;
  for (int i=0; i<(int)v.size(); i++) {
    if (v.back()==v[i]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
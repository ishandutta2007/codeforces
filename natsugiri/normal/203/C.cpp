#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
int n, d, a, b;
vector<pair<LL,int> >v;
vector<int>ans;
int main(){

  scanf("%d%d%d%d", &n,&d, &a, &b);
  for (int i=0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back(make_pair((LL)x*a+(LL)y*b, i+1));
  }
  sort(v.begin(), v.end());
  LL s=0;
  for (int i=0; i<n; i++) {
    s+=v[i].first;
    if (s<=d) ans.push_back(v[i].second);
  }
  
  printf("%d\n", ans.size());
  for (int i=0; i<(int)ans.size(); i++) {
    printf("%d%c", ans[i], i+1==ans.size()?'\n':' ');
  }
  return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n;
map<int,pair<int,int> >mp;

void add(int x, int t) {
  if (mp.count(x)) {
    if (t) mp[x].second++;
    else mp[x].first++;
  } else {
    if (t) mp[x]=make_pair(0,1);
    else mp[x]=make_pair(1,0);
  }
}
  
  

int main(){
  int x, y;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d%d", &x, &y);
    add(x,0);
    if (x!=y) add(y,1);
  }
  int ans=-1, m=(n+1)/2;
  for (__typeof(mp.end())it=mp.begin(); it!=mp.end(); it++) {
    pair<int,int>r=(*it).second;
    if (r.first+r.second>=m) {
      int t=max(m-r.first,0);
      if (ans==-1 || ans>t) ans=t;
    }
  }
  printf("%d\n", ans);
  return 0;
}
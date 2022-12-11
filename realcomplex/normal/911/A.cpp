#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
int main(){
  int n;
  cin >> n;
  pair<int,int>el[n];
  for(int i = 0;i<n;i++){
    cin >> el[i].fi;
    el[i].se=i;
  }
  sort(el,el+n);
  int ans = 2e9;
  for(int i = 1;i<n;i++){
    if(el[i].fi!=el[i-1].fi)break;
    ans=min(ans,el[i].se-el[i-1].se);
  }
  cout << ans;
  return 0;
}
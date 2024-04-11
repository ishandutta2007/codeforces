#include<bits/stdc++.h>

using namespace std;

pair<int,int> analyze(){
  int n;
  cin >> n;
  int ef=2e9,ls=-2e9;
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    ef=min(ef,r);
    ls=max(ls,l);
  }
  return {ef,ls};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  pair<int,int> a=analyze();
  pair<int,int> b=analyze();
  cout << max({0,a.second-b.first,b.second-a.first}) << '\n';
  return 0;
}
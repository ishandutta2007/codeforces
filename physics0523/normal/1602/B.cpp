#include<bits/stdc++.h>

using namespace std;

vector<int> f(vector<int> &a){
  map<int,int> mp;
  vector<int> b;
  for(auto &nx : a){mp[nx]++;}
  for(auto &nx : a){b.push_back(mp[nx]);}
  return b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<vector<int>> mem(n+1);
    mem[0]=a;
    for(int i=1;i<=n;i++){mem[i]=f(mem[i-1]);}
    int q;
    cin >> q;
    while(q>0){
      q--;
      int x,k;
      cin >> x >> k;
      x--;
      k=min(k,n);
      cout << mem[k][x] << '\n';
    }
  }
  return 0;
}
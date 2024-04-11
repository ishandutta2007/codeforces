#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    if(k==n-1){
      if(n==4){cout << "-1\n";}
      else{
        cout << 1 << ' ' << n-3 << '\n';
        cout << 2 << ' ' << n-2 << '\n';
        k-=3;
        cout << n-1 << ' ' << k << '\n';
        vector<pair<int,int>> vp;
        for(int i=3;i<(n/2);i++){
          vp.push_back({i,(n-1)^i});
        }
        for(auto &nx : vp){
          if(nx.first==k){nx.first=0;}
          if(nx.second==k){nx.second=0;}
          cout << nx.first << ' ' << nx.second << '\n';
        }
      }
      continue;
    }
    cout << n-1 << ' ' << k << '\n';
    vector<pair<int,int>> vp;
    for(int i=1;i<(n/2);i++){
      vp.push_back({i,(n-1)^i});
    }
    for(auto &nx : vp){
      if(nx.first==k){nx.first=0;}
      if(nx.second==k){nx.second=0;}
      cout << nx.first << ' ' << nx.second << '\n';
    }
  }
  return 0;
}
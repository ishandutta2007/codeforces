#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,dx,dy;
  cin >> n >> m >> dx >> dy;
  vector<int> mem(n);
  int v=0;
  for(int i=0;i<n;i++){
    mem[v]=i;
    v+=dx;v%=n;
  }
  map<int,int> mp;
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    long long del=dy;
    del*=mem[x];del%=n;
    y+=(n-del);y%=n;
    mp[y]++;
  }
  int res=-1;
  for(auto &nx : mp){
    if(res==-1){res=nx.first;}
    else if(mp[res]<nx.second){res=nx.first;}
  }
  cout << 0 << ' ' << res << '\n';
  return 0;
}
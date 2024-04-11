#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,b;
  cin >> n >> b;
  b*=8;
  b/=n;
  b=min(b,20);
  b=(1<<b);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mp[v]++;
  }
  vector<int> rw;
  for(auto &nx : mp){rw.push_back(nx.second);}
  if(rw.size()<=b){cout << "0\n";return 0;}
  for(int i=1;i<rw.size();i++){
    rw[i]+=rw[i-1];
  }
  int res=rw[b-1];
  for(int i=b;i<rw.size();i++){
    res=max(res,rw[i]-rw[i-b]);
  }

  cout << n-res << '\n';
  return 0;
}
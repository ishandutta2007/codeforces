#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  Graph g(n);
  for(int i=0;i<q;i++){
    int l,x;
    cin >> l >> x;
    l--;
    g[l].push_back({x,i});
  }
  vector<int> res(q);
  vector<bool> jud(1<<20);
  jud[0]=true;
  int cres=1;
  for(int i=0;i<n;i++){
    if(jud[a[i]]){cres*=2;cres%=mod;}
    else{
      for(int j=0;j<(1<<20);j++){
        if(jud[j]){jud[j^a[i]]=true;}
      }
    }
    for(auto &nx : g[i]){
      if(jud[nx.first]){res[nx.second]=cres;}
      else{res[nx.second]=0;}
    }
  }
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}
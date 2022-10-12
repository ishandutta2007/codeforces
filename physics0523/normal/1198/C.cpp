#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> fl(3*n+5,0);
    vector<int> mtg;
    for(int i=1;i<=m;i++){
      int u,v;
      cin >> u >> v;
      if(fl[u]==0 && fl[v]==0){
        fl[u]=1;
        fl[v]=1;
        mtg.push_back(i);
      }
    }
    if(mtg.size()>=n){
      while(mtg.size()>n){mtg.pop_back();}
      cout << "Matching\n";
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << mtg[i];
      }cout << '\n';
    }
    else{
      cout << "IndSet\n";
      vector<int> res;
      for(int i=1;i<=3*n;i++){
        if(fl[i]==0){res.push_back(i);}
      }
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << res[i];
      }cout << '\n';
    }
  }
  return 0;
}
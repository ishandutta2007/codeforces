#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int lb(int p,int x){
  int st=1,fi=1e6;
  while(st<=fi){
    int te=(st+fi)/2;
    if((p/te)>x){st=te+1;}
    else{fi=te-1;}
  }
  return st;
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
    vector<vector<pi>> mem(n+1);
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      mem[lb(i,v)].push_back({lb(i,v-1)-1,i});
      // cout << lb(i,v) << " " << lb(i,v-1)-1 << '\n';
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
      for(auto &nx : mem[i]){pq.push(nx);}
      res[pq.top().second]=i;pq.pop();
    }
    for(int i=1;i<=n;i++){
      if(i-1){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}
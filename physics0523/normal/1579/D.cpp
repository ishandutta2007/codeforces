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
    int n;
    cin >> n;
    priority_queue<pi> pq;
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      if(v!=0){pq.push({v,i});}
    }
    vector<pi> res;
    while(pq.size()>=2){
      pi o1=pq.top();pq.pop();
      pi o2=pq.top();pq.pop();
      o1.first--;o2.first--;
      res.push_back({o1.second,o2.second});
      if(o1.first){pq.push(o1);}
      if(o2.first){pq.push(o2);}
    }
    cout << res.size() << '\n';
    for(auto &nx : res){cout << nx.first << ' ' << nx.second << '\n';}
  }
  return 0;
}
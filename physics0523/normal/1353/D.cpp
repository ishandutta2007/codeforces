#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(make_pair(n,make_pair(-1,-n)));
    vector<int> res(n+1);
    int k=1;
    while(!pq.empty()){
      pair<int,pair<int,int>> od=pq.top();
      pq.pop();
      int cst=-od.second.first;
      int cfi=-od.second.second;
      int cp=(cst+cfi)/2;
      res[cp]=k;k++;
      if(cst<cp){
        pq.push(make_pair(cp-cst,make_pair(-cst,-(cp-1))));
      }
      if(cp<cfi){
        pq.push(make_pair(cfi-cp,make_pair(-(cp+1),-cfi)));        
      }
    }
    for(int i=1;i<=n;i++){
      if(i!=1){cout << ' ';}
      cout << res[i];
    }
    cout << '\n';
  }
}
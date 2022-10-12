#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> res;
  vector<int> fl(n+1,0);
  vector<pair<int,int>> pv;
  vector<int> l(n+1),r(n+1);
  
  for(int i=1;i<=n;i++){
    cin >> l[i] >> r[i];
    l[i]*=2;
    r[i]*=2;r[i]++;
    pv.push_back(make_pair(l[i],i));
    pv.push_back(make_pair(r[i],-i));
  }
  sort(pv.begin(),pv.end());
  
  priority_queue<pair<int,int>> pq;
  int cs=0;
  for(auto &e : pv){
    //cout << e.first << ' ' << e.second << '\n';
    if(e.second>0){
      fl[e.second]=1;
      cs++;
      pq.push(make_pair(r[e.second],e.second));
      if(cs>k){
        pair<int,int> od;
        while(1){
          od=pq.top();
          pq.pop();
          if(fl[od.second]==1){break;}
        }
        cs--;
        res.push_back(od.second);
        fl[od.second]=0;
      }
    }
    else{
      if(fl[-e.second]==1){
        cs--;
        fl[-e.second]=0;
      }
    }
  }
  
  cout << res.size() << '\n';
  int sfl=0;
  for(auto &e : res){
    if(sfl==1){cout << ' ';}
    cout << e;
    sfl=1;
  }cout << '\n';
  return 0;
}
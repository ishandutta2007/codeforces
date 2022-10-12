#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  priority_queue<pi,vector<pi>,greater<pi>> bus;
  priority_queue<int,vector<int>,greater<int>> fr;
  for(int i=1;i<=n;i++){fr.push(i);}
  while(q>0){
    q--;
    int t,k,d;
    cin >> t >> k >> d;
    while(!bus.empty()){
      if(bus.top().first<=t){
        fr.push(bus.top().second);
        bus.pop();
      }
      else{break;}
    }
    if(fr.size()<k){cout << "-1\n";continue;}
    int res=0;
    for(int i=0;i<k;i++){
      int od=fr.top();fr.pop();
      res+=od;
      bus.push({t+d,od});
    }
    cout << res << '\n';
  }
  return 0;
}
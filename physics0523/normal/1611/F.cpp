#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,s;
    cin >> n >> s;
    long long h=0;
    priority_queue<pl> pq;
    long long st=1e18,fi=-1e18;
    for(int i=1;i<=n+1;i++){
      pq.push({h-s,i});
      long long v;
      if(i<=n){cin >> v;}
      else{v=-1e18;}
      h+=v;
      while(!pq.empty() && pq.top().first>h){
        pl od=pq.top();pq.pop();
        if((fi-st)<((i-1)-od.second)){
          st=od.second;
          fi=i-1;
        }
      }
    }
    if(st>fi){cout << "-1\n";}
    else{cout << st << ' ' << fi << '\n';}
  }
  return 0;
}
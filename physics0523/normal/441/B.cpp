#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,v;
  cin >> n >> v;
  vector<int> mem(3390,0);
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    mem[a]+=b;
  }
  int res=0;
  priority_queue<pi,vector<pi>,greater<pi>> pq;
  for(int i=1;i<=3390;i++){
    if(mem[i]>0){pq.push({i,mem[i]});}
    int rem=v;
    while(!pq.empty() && rem>0){
      pi od=pq.top();pq.pop();
      if(od.first<=i-2){continue;}
      int del=min(rem,od.second);
      rem-=del;
      od.second-=del;
      res+=del;
      if(od.second>0){pq.push(od);}
    }
  }
  cout << res << '\n';
  return 0;
}
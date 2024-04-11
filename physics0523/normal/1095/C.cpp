#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  if(n<k){cout << "NO\n";return 0;}
  priority_queue<int> pq;
  for(int i=0;i<30;i++){
    if(n&(1<<i)){pq.push(1<<i);}
  }
  if(pq.size()>k){cout << "NO\n";return 0;}
  while(pq.size()<k){
    int od=pq.top();pq.pop();
    pq.push(od/2);
    pq.push(od/2);
  }
  cout << "YES\n";
  for(int i=0;i<k;i++){
    if(i){cout << ' ';}
    int od=pq.top();pq.pop();
    cout << od;
  }cout << '\n';
  return 0;
}
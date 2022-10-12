#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    multiset<long long> ms;
    long long sig=0;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      ms.insert(v);
      sig+=v;
    }
    priority_queue<long long> pq;
    pq.push(sig);
    int pc=1;
    while(pc<=n && !ms.empty()){
      long long od=pq.top();pq.pop();
      if(ms.find(od)!=ms.end()){
        ms.erase(ms.find(od));
        continue;
      }
      pc++;
      if(od==1){break;}
      pq.push(od/2);
      pq.push((od/2)+(od%2));
    }
    if(ms.empty()){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
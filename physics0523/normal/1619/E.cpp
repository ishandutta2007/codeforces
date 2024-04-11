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
    vector<long long> cnt(n+5,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      cnt[v]++;
    }
    int i=0;
    long long cres=0;
    priority_queue<long long> pq;
    while(i<=n){
      if(i){cout << ' ';}
      cout << cres+cnt[i];
      if(cnt[i]==0){
        if(pq.empty()){i++;break;}
        long long od=pq.top();pq.pop();
        cres+=(i-od);
      }
      else{
        while(cnt[i]>1){pq.push(i);cnt[i]--;}
      }
      i++;
    }
    while(i<=n){
      if(i){cout << ' ';}
      cout << "-1";
      i++;
    }
    cout << '\n';
  }
  return 0;
}
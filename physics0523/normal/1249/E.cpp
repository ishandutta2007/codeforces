#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,c;
  cin >> n >> c;
  vector<int> a(n),b(n);
  for(int i=0;i<(n-1);i++){cin >> a[i];}
  for(int i=0;i<(n-1);i++){cin >> b[i];}
  vector<int> md(2*n,-1);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push(make_pair(0,0));
  while(!pq.empty()){
    pair<int,int> od=pq.top();
    pq.pop();
    int cv=od.second,ct=od.first;
    if(md[cv]!=-1){continue;}
    md[cv]=ct;
    if(cv<n){
      if(cv!=0){
        pq.push(make_pair(ct+a[cv-1],cv-1));        
      }
      if(cv!=(n-1)){
        pq.push(make_pair(ct+a[cv],cv+1));
      }
      pq.push(make_pair(ct+c,cv+n));
    }
    else{
      if(cv!=n){
        pq.push(make_pair(ct+b[(cv-n)-1],cv-1));        
      }
      if(cv!=(2*n-1)){
        pq.push(make_pair(ct+b[(cv-n)],cv+1));
      }
      pq.push(make_pair(ct,cv-n));
    }
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << md[i];
  }cout << '\n';
  return 0;
}
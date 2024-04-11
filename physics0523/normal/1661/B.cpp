#include<bits/stdc++.h>

using namespace std;

vector<int> d(32768);

void work(){
  for(auto &nx : d){nx=1e9;}
  d[0]=0;
  d[32767]=1;
  d[16384]=1;
  queue<int> q;
  q.push(32767);
  q.push(16384);
  while(!q.empty()){
    int od=q.front();q.pop();
    if(d[od-1]>d[od]+1){
      d[od-1]=d[od]+1;
      q.push(od-1);
    }
    if(od%2==0){
      if(d[od/2]>d[od]+1){
        d[od/2]=d[od]+1;
        q.push(od/2);
      }
      int half=16384;
      if(d[half+od/2]>d[od]+1){
        d[half+od/2]=d[od]+1;
        q.push(half+od/2);
      }
    }
  }
}

int main(){
  work();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    cout << d[n] << '\n';
  }
  return 0;
}
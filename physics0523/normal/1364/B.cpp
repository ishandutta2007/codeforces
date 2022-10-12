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
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    vector<int> q;
    q.push_back(p[0]);
    for(int i=1;i<n-1;i++){
      if(p[i-1]<p[i] && p[i]<p[i+1]){continue;}
      if(p[i-1]>p[i] && p[i]>p[i+1]){continue;}
      q.push_back(p[i]);
    }
    q.push_back(p[n-1]);

    cout << q.size() << '\n';
    bool f=false;
    for(auto &nx : q){
      if(f){cout << ' ';}
      f=true;
      cout << nx;
    }cout << '\n';
  }
  return 0;
}
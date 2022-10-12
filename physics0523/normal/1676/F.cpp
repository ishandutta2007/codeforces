#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
      if(mp[v]==k){st.insert(v);}
    }
    if(st.empty()){cout << "-1\n";continue;}
    int l=-1e9,ml=-1;
    int c=-1e9,cl=1;
    for(auto &nx : st){
      if(nx==c+cl){cl++;}
      else{c=nx;cl=1;}
      if(ml<cl){
        l=c;ml=cl;
      }
    }
    cout << l << ' ' << l+ml-1 << '\n';
  }
  return 0;
}
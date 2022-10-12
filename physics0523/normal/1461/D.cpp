#include<bits/stdc++.h>

using namespace std;

set<long long> st;
void solve(vector<long long> &a){
  if(a.empty()){return;}
  if(a[0]==a.back()){return;}
  long long mid=(a[0]+a.back())/2;
  vector<long long> pre,suf;
  long long pres=0,sufs=0;
  for(auto &nx : a){
    if(nx<=mid){
      pre.push_back(nx);
      pres+=nx;
    }
    else{
      suf.push_back(nx);
      sufs+=nx;
    }
  }
  st.insert(pres);
  st.insert(sufs);
  solve(pre);
  solve(suf);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    vector<long long> a(n);
    long long sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    sort(a.begin(),a.end());
    st.clear();
    st.insert(sig);
    solve(a);
    while(q>0){
      q--;
      long long v;
      cin >> v;
      if(st.find(v)==st.end()){cout << "No\n";}
      else{cout << "Yes\n";}
    }
  }
  return 0;
}
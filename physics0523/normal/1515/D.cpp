#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,l,r;
    cin >> n >> l >> r;
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<l;i++){
      int v;
      cin >> v;
      st.insert(v);
      mp[-v]++;
    }
    for(int i=0;i<r;i++){
      int v;
      cin >> v;
      st.insert(v);
      mp[v]++;
    }
    int res=0;
    int rl=0,rr=0;
    int pl=0,pr=0;
    for(auto &nx : st){
      int tg=min(mp[nx],mp[-nx]);
      mp[nx]-=tg;
      mp[-nx]-=tg;

      rl+=mp[nx];
      rr+=mp[-nx];
      pl+=mp[nx]/2;
      pr+=mp[-nx]/2;
    }
    if(rl<rr){
      swap(rl,rr);
      swap(pl,pr);
    }
    res+=(rl-rr)/2;
    res+=(rl+rr)/2;
    res-=min(pl,(rl-rr)/2);
    cout << res << '\n';
  }
  return 0;
}
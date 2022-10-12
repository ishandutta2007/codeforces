#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  set<long long> st;
  for(auto &nx : a){
    cin >> nx;
    st.insert(nx);
  }
  vector<long long> res;
  for(auto &nx : a){
    for(int i=0;i<35;i++){
      vector<long long> cur={nx};
      long long bk=nx-(1ll<<i);
      long long fw=nx+(1ll<<i);
      if(st.find(bk)!=st.end()){cur.push_back(bk);}
      if(st.find(fw)!=st.end()){cur.push_back(fw);}
      if(res.size()<cur.size()){res=cur;}
    }
  }

  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}
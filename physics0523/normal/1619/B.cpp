#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  set<int> st;
  for(int i=1;i*i<=1000000000;i++){
    st.insert(i*i);
  }
  for(int i=1;i*i*i<=1000000000;i++){
    st.insert(i*i*i);
  }
  vector<int> v;
  for(auto &nx : st){v.push_back(nx);}
  v.push_back(2e9);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int st=0,fi=v.size()-1;
    while(st<=fi){
      int te=(st+fi)/2;
      if(v[te]<=n){st=te+1;}
      else{fi=te-1;}
    }
    cout << st << '\n';
  }
  return 0;
}
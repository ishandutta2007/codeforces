#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  set<long long> st;
  for(int i=2;i<=61;i++){
    long long whole=(1ll<<i)-1;
    for(int j=0;j<(i-1);j++){
      st.insert(whole^(1ll<<j));
    }
  }
  long long a,b,res=0;
  cin >> a >> b;
  for(auto &nx : st){
    if(a<=nx && nx<=b){res++;}
  }
  cout << res << '\n';
  return 0;
}
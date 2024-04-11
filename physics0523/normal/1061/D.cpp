#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,x,y;
  cin >> n >> x >> y;
  vector<pl> sg(n);
  for(auto &nx : sg){
    cin >> nx.first;
    cin >> nx.second;
  }
  sort(sg.begin(),sg.end());
  multiset<long long> st;
  long long res=0;
  for(auto &nx : sg){
    auto it=st.lower_bound(nx.first);
    if(it!=st.begin()){
      it--;
      long long val=y*(nx.first-(*it));
      if(val<x){
        res+=val;res%=mod;
        st.erase(it);
      }
      else{res+=x;res%=mod;}
    }
    else{
      res+=x;res%=mod;
    }
    res+=y*(nx.second-nx.first);res%=mod;
    st.insert(nx.second);
  }
  cout << res << '\n';
  return 0;
}
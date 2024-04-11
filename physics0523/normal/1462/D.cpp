#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    int sig=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      sig+=a[i];
    }
    set<int> st;
    for(int i=1;i*i<=sig;i++){
      if(sig%i==0){
        st.insert(i);
        st.insert(sig/i);
      }
    }
    for(auto &i : st){
      int cs=0;
      for(int j=0;j<n;j++){
        cs+=a[j];
        if(cs==i){cs=0;}
        else if(cs>i){cs=-1;break;}
      }
      if(cs==0){cout << n-(sig/i) << '\n';break;}
    }
  }
}
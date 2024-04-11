#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  set<long long> st1;
  set<long long> st2;
  for(int i=0;i<10;i++){
    long long v=i;
    st1.insert(i);
    st2.insert(i);
    for(int k=0;k<10;k++){
      v*=10;v+=i;
      st1.insert(v);
      st2.insert(v);
    }
    for(int j=0;j<10;j++){
      for(int h=0;h<(1<<10);h++){
        long long v=0;
        for(int k=0;k<10;k++){
          v*=10;
          if(h&(1<<k)){v+=i;}else{v+=j;}
          st2.insert(v);
        }
      }
    }
  }
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    if(k==1){cout << (*st1.lower_bound(n)) << '\n';}
    else{cout << (*st2.lower_bound(n)) << '\n';}
  }
  return 0;
}
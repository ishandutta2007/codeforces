#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

string sub1(string s){
  int l=s.size();
  for(int i=l-1;i>=0;i--){
    if(s[i]=='1'){
      s[i]='0';
      for(int j=i+1;j<l;j++){s[j]='1';}
      return s;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string l,r;
  cin >> n >> l >> r;
  if(n==1){cout << r << '\n';return 0;}
  if(l[0]!=r[0]){
    for(int i=0;i<n;i++){cout << "1";}
    cout << "\n";
    return 0;
  }
  if(r[n-1]=='1'){cout << r << '\n';return 0;}
  if(l<=sub1(sub1(r))){
    r[n-1]='1';
  }
  cout << r << '\n';
  return 0;
}
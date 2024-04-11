#include<bits/stdc++.h>

using namespace std;

int solve(int n,int k){
  int cyc=(n-1);
  int p=k/cyc,q=k%cyc;
  if(q==0){p--;q=cyc;}
  return p*n+q;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    cout << solve(n,k) << '\n';
  }
  return 0;
}
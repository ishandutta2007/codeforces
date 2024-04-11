#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long s,n,k;
    cin >> s >> n >> k;
    if(s==k){cout << "YES\n";continue;}
    if(s<k){cout << "NO\n";continue;}
    long long minh;
    minh=2*k*(n/k);
    minh+=(n%k);
    if(minh<=s){cout << "NO\n";}else{cout << "YES\n";}
  }
  return 0;
}
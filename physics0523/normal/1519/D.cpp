#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<long long> b(n);
  for(auto &nx : b){cin >> nx;}

  long long org=0,res;
  for(int i=0;i<n;i++){org+=a[i]*b[i];}
  res=org;
  for(int i=0;i<n-1;i++){
    int st=i,fi=i+1;
    long long cres=org;
    while(0<=st && fi<n){
      cres-=(a[st]*b[st]+a[fi]*b[fi]);
      cres+=(a[st]*b[fi]+a[fi]*b[st]);
      res=max(res,cres);
      st--;fi++;
    }
  }
  for(int i=0;i<n-2;i++){
    int st=i,fi=i+2;
    long long cres=org;
    while(0<=st && fi<n){
      cres-=(a[st]*b[st]+a[fi]*b[fi]);
      cres+=(a[st]*b[fi]+a[fi]*b[st]);
      res=max(res,cres);
      st--;fi++;
    }
  }
  cout << res << '\n';
  return 0;
}
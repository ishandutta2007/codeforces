#include<bits/stdc++.h>

using namespace std;

long long f(vector<long long> a,long long k){
  long long res=0;
  for(auto &nx : a){
    res+=(nx/k);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k,b,s;
    cin >> n >> k >> b >> s;
    vector<long long> res(n,0);
    res[0]=k*b;
    s-=k*b;
    for(int i=0;(i<n && s>0);i++){
      long long add=min(s,k-1);
      s-=add;
      res[i]+=add;
    }
    if(f(res,k)==b && s==0){
      for(int i=0;i<n;i++){
        if(i){cout << " ";}
        cout << res[i];
      }cout << "\n";
    }
    else{cout << "-1\n";}
  }
  return 0;
}
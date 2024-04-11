#include<bits/stdc++.h>

using namespace std;

bool jud(long long x,vector<long long> &a){
  for(auto &nx : a){
    if(nx%x==0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a,b;
    for(long long i=0;i<n;i++){
      long long v;
      cin >> v;
      if(i%2){b.push_back(v);}
      else{a.push_back(v);}
    }
    long long d=a[0];
    for(auto &nx : a){d=gcd(d,nx);}
    if(jud(d,b)){cout << d << '\n';continue;}

    d=b[0];
    for(auto &nx : b){d=gcd(d,nx);}
    if(jud(d,a)){cout << d << '\n';continue;}
    cout << "0\n";
  }
  return 0;
}
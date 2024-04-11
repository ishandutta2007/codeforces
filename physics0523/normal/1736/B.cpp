#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> b(n+1,1);
    for(int i=0;i<n;i++){
      b[i]=lcm(b[i],a[i]);
      b[i+1]=lcm(b[i+1],a[i]);
    }
    bool ok=true;
    for(int i=0;i<n;i++){
      if(gcd(b[i],b[i+1])!=a[i]){ok=false;break;}
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
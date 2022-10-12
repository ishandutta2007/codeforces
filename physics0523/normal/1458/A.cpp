#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<long long> a(n),b(m);
  for(int i=0;i<n;i++){cin >> a[i];}
  for(int i=0;i<m;i++){cin >> b[i];}
  sort(a.begin(),a.end());
  if(a[0]==a[n-1]){
    for(int i=0;i<m;i++){
      if(i){cout << ' ';}
      cout << (a[0]+b[i]);
    }cout << '\n';
    return 0;
  }
  long long g=a[n-1]-a[0];
  for(int i=1;i<n;i++){
    if(a[i]!=a[i-1]){g=gcd(a[i]-a[i-1],g);}
  }
  for(int i=0;i<m;i++){
    if(i){cout << ' ';}
    cout << gcd(a[0]+b[i],g);
  }cout << '\n';
}
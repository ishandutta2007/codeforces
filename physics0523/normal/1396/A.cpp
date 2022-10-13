#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,a[524288];
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  
  if(n==1){
      cout << "1 1" << '\n';
      cout << "0" << '\n';
      cout << "1 1" << '\n';
      cout << "0" << '\n';
      cout << "1 1" << '\n';
      cout << -a[1] << '\n';
      return 0;
  }

  cout << 1ll << ' ' << n-1ll << '\n';
  for(int i=1;i<n;i++){
    if(i!=1){cout << ' ';}
    if(i!=1){cout << 0;continue;}
    cout << a[i]*(n-1ll);
    a[i]*=n;
  }
  cout << '\n';
  
  cout << 2ll << ' ' << n << '\n';
  for(int i=2;i<=n;i++){
    if(i!=2){cout << ' ';}
    cout << a[i]*(n-1ll);
    a[i]*=n;
  }
  cout << '\n';
  
  cout << 1ll << ' ' << n << '\n';
  for(int i=1;i<=n;i++){
    if(i!=1){cout << ' ';}
    cout << -a[i];
  }cout << '\n';
  return 0;
}
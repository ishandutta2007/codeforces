#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  for(ll i = 0;i<=n;i++){
    if(i*a>n)break;
    if((n-(i*a))%b==0){
      cout << "YES\n" << i << " " << (n-(i*a))/b << "\n";
      exit(0);
    }
  }
  cout << "NO\n";
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  if(k==1){cout << "Yes\n";return 0;}
  int l=1;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    l=lcm(l,gcd(v,k));
  }
  if(l==k){cout << "Yes\n";}else{cout << "No\n";}
  return 0;
}
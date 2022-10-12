#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,l,r;
  cin >> n >> l >> r;

  long long mi=0,ma=0;
  mi=(n-l);
  for(int i=0;i<l;i++){mi+=(1ll<<i);}

  ma=(n-r)*(1ll<<(r-1));
  for(int i=0;i<r;i++){ma+=(1ll<<i);}

  cout << mi << " " << ma << "\n";
  return 0;
}
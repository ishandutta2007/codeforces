#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  vector<long long> a(n);
  long long sig=0;
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
  }
  sort(a.begin(),a.end());
  long long rem=0,h=1;
  for(int i=0;i<n-1;i++){
    rem++;
    if(h<=a[i]){h++;}
  }
  rem+=max(1ll,a[n-1]-h+1);
  //cout << rem << '\n';
  cout << sig-rem << '\n';
  return 0;
}
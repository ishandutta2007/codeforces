#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<long long> a(n);
  long long sig=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sig+=a[i];
  }
  sort(a.begin(),a.end());
  long long res=0,ck;
  bool fl=false;
  for(int i=0;i<n;i++){
    if(fl){
      ck++;
      res+=a[i]*ck;
      continue;
    }
    sig-=a[i];
    res+=a[i]*(i/(k+1));
    if(sig>=0){
      fl=true;
      ck=(i/(k+1));
    }
  }
  cout << res << '\n';
  return 0;
}
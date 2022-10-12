#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> a(n),b(m,0);
  for(int i=0;i<n;i++){cin >> a[i];}
  sort(a.begin(),a.end());
  long long res=0;
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    b[i%m]+=a[i];
    res+=b[i%m];
    cout << res;
  }
  cout << '\n';
  return 0;
}
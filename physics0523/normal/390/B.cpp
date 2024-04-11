#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n),b(n);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}
  long long res=0;
  for(int i=0;i<n;i++){
    if(2*a[i]<b[i]){res--;}
    else if(b[i]==1){res--;}
    else{
      res+=(b[i]/2)*(b[i]/2 + (b[i]%2));
    }
  }
  cout << res << "\n";
  return 0;
}
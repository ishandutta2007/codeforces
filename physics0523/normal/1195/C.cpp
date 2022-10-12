#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n),b(n);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}

  long long f1=0,f2=0,f3=0;
  for(int i=0;i<n;i++){
    long long n1,n2,n3;
    n1=max(f2,f3)+b[i];
    n2=max(f1,f3)+a[i];
    n3=max({f1,f2,f3});
    f1=n1;f2=n2;f3=n3;
  }
  cout << max({f1,f2,f3}) << "\n";
  return 0;
}
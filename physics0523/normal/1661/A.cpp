#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long res=0;
    vector<long long> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    for(int i=1;i<n;i++){
      res+=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]),abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
    }
    cout << res << '\n';
  }
  return 0;
}
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
    vector<long long> a(n);
    long long res=0;
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=1;i<n;i++){
      res=max(a[i-1]*a[i],res);
    }
    cout << res << '\n';
  }
  return 0;
}
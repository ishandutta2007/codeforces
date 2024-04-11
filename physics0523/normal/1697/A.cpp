#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      m-=v;
    }
    cout << max(0ll,-m) << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,l,r,k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    int res=0;
    for(int i=0;i<n;i++){
      if(l<=a[i] && a[i]<=r && a[i]<=k){
        k-=a[i];
        res++;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
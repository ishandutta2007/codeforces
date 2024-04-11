#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    vector<long long> res(k,0);
    for(int i=0;i<n;i++){
      res[i%k]=max(res[i%k],a[i]);
    }
    long long sig=0;
    for(auto &nx : res){sig+=nx;}
    cout << sig << "\n";
  }
  return 0;
}
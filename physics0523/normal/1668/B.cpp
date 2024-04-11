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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long res=n;
    for(int i=1;i<n;i++){res+=a[i];}
    res+=a[n-1];
    if(res<=m){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
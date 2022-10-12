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
    vector<long long> v(n);
    long long k=0;
    for(auto &nx : v){
      cin >> nx;
      while(nx%2==0){
        nx/=2;k++;
      }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(k>0){
      k--;v[0]*=2;
    }
    long long res=0;
    for(auto &nx : v){res+=nx;}
    cout << res << '\n';
  }
  return 0;
}
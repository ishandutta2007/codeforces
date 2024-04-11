#include<bits/stdc++.h>

using namespace std;

long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    k++;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long res=0;
    for(int i=n-1;i>=0;i--){
      long long ur=0;
      for(int j=0;j<i;j++){
        ur+=llpow(10,a[j+1]-a[j])-1;
      }
      long long ce=llpow(10,a[i]);
      long long cur=max(0ll,k-ur);
      res+=ce*cur;k-=cur;
      //cerr << cur << a[i] << '\n';
    }
    cout << res << '\n';
  }
  return 0;
}
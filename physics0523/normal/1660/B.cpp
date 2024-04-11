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
    long long sig=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    sort(a.begin(),a.end());
    if(n==1){
      if(a[0]==1){cout << "YES\n";}
      else{cout << "NO\n";}
      continue;
    }
    if(a[n-1]-a[n-2]>1){cout << "NO\n";continue;}
    long long minl=2*a[n-1]-1;
    if(sig>=minl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
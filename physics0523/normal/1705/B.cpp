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
    for(auto &nx : a){cin >> nx;}
    long long res=0;
    for(int i=0;i<n-1;i++){res+=a[i];}
    bool fl=false;
    for(int i=0;i<n-1;i++){
      if(a[i]>0){fl=true;}
      else if(fl){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long k,n;
    cin >> k >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    long long res=n,nd=0;
    for(int i=0;i<n;i++){
      nd+=(k-a[i]);
      //cout << nd << '\n';
      if(nd>=k){res=i;break;}
    }
    cout << res << '\n';
  }
  return 0;
}
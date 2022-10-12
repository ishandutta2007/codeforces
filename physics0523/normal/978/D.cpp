#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  if(n==1){cout << "0\n";return 0;}
  int res=1e9;
  for(long long i=-1;i<=1;i++){
    for(long long j=-1;j<=1;j++){
      vector<long long> ca={a[0]+i,a[1]+j};
      long long cd=ca[1]-ca[0];
      for(int k=2;k<n;k++){
        ca.push_back(ca.back()+cd);
      }
      int cr=0;
      for(int k=0;k<n;k++){
        int ab=abs(a[k]-ca[k]);
        if(ab>1){cr=1e9;break;}
        cr+=ab;
      }
      res=min(res,cr);
    }
  }
  if(res>5e8){res=-1;}
  cout << res << '\n';
  return 0;
}
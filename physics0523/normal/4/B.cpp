#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,s;
  cin >> n >> s;
  long long mi=0,ma=0;
  vector<long long> l(n),r(n);
  for(int i=0;i<n;i++){
    cin >> l[i] >> r[i];
    mi+=l[i];
    ma+=r[i];
  }
  if(mi<=s && s<=ma){
    cout << "YES\n";
    long long y=s-mi;
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      long long dlt=min(y,r[i]-l[i]);
      cout << l[i]+dlt;
      y-=dlt;
    }cout << '\n';
  }
  else{cout << "NO\n";}
  return 0;
}
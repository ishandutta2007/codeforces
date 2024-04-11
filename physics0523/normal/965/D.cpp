#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long w,l;
  cin >> w >> l;
  vector<long long> a(w);
  long long res=4154118101919364364;
  for(int i=1;i<=w-1;i++){
    cin >> a[i];
    a[i]+=a[i-1];
    if(i>=l){res=min(a[i]-a[i-l],res);}
  }
  cout << res << '\n';
  return 0;
}
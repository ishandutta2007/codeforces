#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  long long v;

  vector<long long> lr(n,0);
  v=0;
  for(int i=1;i<n;i++){
    v+=max(0ll,a[i-1]-a[i]);
    lr[i]=v;
  }

  vector<long long> rl(n,0);
  v=0;
  for(int i=n-2;i>=0;i--){
    v+=max(0ll,a[i+1]-a[i]);
    rl[i]=v;
  }

  for(int i=0;i<q;i++){
    int x,y;
    cin >> x >> y;
    x--;y--;
    if(x<y){cout << lr[y]-lr[x] << "\n";}
    else{cout << rl[y]-rl[x] << "\n";}
  }

  return 0;
}
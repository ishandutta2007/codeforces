#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n+1),cd(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  int pt=1e9;
  for(int i=n;i>=1;i--){
    if(i!=n && a[i]!=a[i+1]){pt=i+1;}
    cd[i]=pt;
  }
  while(q>0){
    q--;
    int l,r,x;
    cin >> l >> r >> x;
    if(a[l]!=x){cout << l << '\n';}
    else if(cd[l]<=r){cout << cd[l] << '\n';}
    else{cout << "-1\n";}
  }
  return 0;
}
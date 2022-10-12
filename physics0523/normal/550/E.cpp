#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  if(n==1){
    if(a[0]==0){cout << "YES\n0\n";}
    else{cout << "NO\n";}
    return 0;
  }
  if(a[n-1]==1){cout << "NO\n";return 0;}
  if(a[n-2]==1){
    cout << "YES\n";
    for(int i=0;i<n;i++){
      if(i){cout << "->";}
      cout << a[i];
    }cout << '\n';
    return 0;
  }
  int z=-1;
  for(int i=n-3;i>=0;i--){
    if(a[i]==0){z=i;break;}
  }
  if(z==-1){cout << "NO\n";return 0;}
  cout << "YES\n";
  vector<int> brk(n+1,0);
  int h=0;
  for(int i=0;i<n-1;i++){
    if(i){cout << "->";}
    if(z<=i && i<=n-2){cout << '(';h++;}
    cout << a[i];
  }
  for(int i=0;i<h;i++){cout << ')';}
  cout << "->0\n";
  return 0;
}
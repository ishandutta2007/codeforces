#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<long long> bk(600000,0);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    bk[a]++;
  }
  for(int i=1;i<=555555;i++){
    bk[i+1]+=(bk[i]/(i+1));
    bk[i]%=(i+1);
  }
  bool ok=true;
  for(int i=0;i<k;i++){
    if(bk[i]){ok=false;}
  }
  if(ok){cout << "Yes\n";}
  else{cout << "No\n";}
  return 0;
}
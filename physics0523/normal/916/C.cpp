#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> rw(n+1);
  cout << 200003 << ' ' << 200003 << '\n';
  for(int i=2;i<=n;i++){
    rw[i]=rw[i-1];
    if(i==n){rw[i]=200003;}
    else{rw[i]++;}
  }
  for(int i=1;i<=n;i++){
    for(int j=1;i+j<=n;j++){
      if(m>0){
        int k=i+j;
        cout << j << ' ' << k << ' ' << rw[k]-rw[j] << '\n';
        m--;
      }
      else{break;}
    }
    if(m==0){break;}
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int st=0,fi=n-1;
  while(st<=fi){
    int te=(st+fi)/2;
    int bx=0,rem=0;
    for(int i=te;i<n;i++){
      if(rem<a[i]){
        bx++;
        rem=k-a[i];
      }
      else{rem-=a[i];}
    }

    if(bx<=m){fi=te-1;}
    else{st=te+1;}
  }
  cout << n-st << '\n';
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int ask_cor(int l,int r){
  cout << "? " << l << ' ' << r << '\n';
  fflush(stdout);

  int res=0;
  for(int i=l;i<=r;i++){
    int v;
    cin >> v;
    if(l<=v && v<=r){res++;}
  }
  return res;
}

void ans(int x){
  cout << "! " << x << '\n';
  fflush(stdout);
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int l=1,r=n;
    while(l<r){
      int te=(l+r)/2;
      if(ask_cor(l,te)%2){r=te;}
      else{l=te+1;}
    }
    ans(l);
  }
  return 0;
}
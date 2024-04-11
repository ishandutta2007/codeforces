#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int col(int x,int y){
  if(x%4==0 && y%4==0){return 0;}
  else{return 1;}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  vector<bitset<6000>> bs(n);
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
    bs[i].reset();
  }

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(col(abs(x[i]-x[j]),abs(y[i]-y[j]))){
        bs[i].set(j);
        bs[j].set(i);
      }
    }
  }

  long long res=0;
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      long long cc=((bs[i]^bs[j])>>(j+1)).count();
      if(col(abs(x[i]-x[j]),abs(y[i]-y[j]))){res+=cc;}
      else{
        res+=(n-(j+1));
        res-=cc;
      }
    }
  }
  cout << res << '\n';
  return 0;
}
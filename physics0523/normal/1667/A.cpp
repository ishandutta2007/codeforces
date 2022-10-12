#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  long long res=8e18;
  for(int i=0;i<n;i++){
    long long cres=0;
    long long x;

    x=0;
    for(int j=i-1;j>=0;j--){
      x++;
      long long d=llceil(x,a[j]);
      cres+=d;
      x=d*a[j];
    }

    x=0;
    for(int j=i+1;j<n;j++){
      x++;
      long long d=llceil(x,a[j]);
      cres+=d;
      x=d*a[j];
    }
    res=min(res,cres);
  }
  cout << res << '\n';
  return 0;
}
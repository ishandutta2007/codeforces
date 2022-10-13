#include<bits/stdc++.h>

using namespace std;

long long n,q;
vector<long long> a;
long long f(long long x){
  if(!(0<=x && x<n-1)){return 0;}
  if(a[x]==a[x+1]){return 0;}
  return (x+1)*(n-(x+1));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  a.resize(n);
  for(auto &nx : a){cin >> nx;}
  long long res=(n*(n+1))/2;
  for(int i=0;i<n-1;i++){
    res+=f(i);
  }
  
  for(int i=0;i<q;i++){
    long long tg,x;
    cin >> tg >> x;
    tg--;
    vector<long long> p={tg-1,tg};
    for(auto &nx : p){res-=f(nx);}
    a[tg]=x;
    for(auto &nx : p){res+=f(nx);}
    cout << res << "\n";
  }
  return 0;
}
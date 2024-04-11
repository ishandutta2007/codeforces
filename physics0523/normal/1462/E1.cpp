#include<bits/stdc++.h>

using namespace std;

long long llnCr(long long a,long long b){
  if(a<b){return 0;}
  long long i,r=1;
  for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> b(n+10,0);
    for(int i=0;i<n;i++){
      cin >> a[i];
      b[a[i]]++;
    }
    long long res=0;
    for(int i=0;i<=n;i++){
      res+=llnCr(b[i],1)*llnCr(b[i+1],1)*llnCr(b[i+2],1);
      res+=llnCr(b[i],2)*llnCr(b[i+1],1);
      res+=llnCr(b[i],1)*llnCr(b[i+1],2);
      res+=llnCr(b[i],2)*llnCr(b[i+2],1);
      res+=llnCr(b[i],1)*llnCr(b[i+2],2);
      res+=llnCr(b[i],3);
    }
    cout << res << '\n';
  }
}
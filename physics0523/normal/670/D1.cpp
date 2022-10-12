#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<long long> a(n),b(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  for(int i=0;i<n;i++){cin >> b[i];}
  long long st=0,fi=3000000000,te;
  while(st<=fi){
    te=(st+fi)/2;
    long long rk=k;
    for(int i=0;i<n;i++){
      long long nd=max(0ll,a[i]*te-b[i]);
      rk-=nd;
      if(rk<0){break;}
    }
    if(rk>=0){st=te+1;}else{fi=te-1;}
  }
  cout << fi << '\n';
  return 0;
}
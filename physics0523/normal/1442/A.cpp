#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    long long cmi=a[0];
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){
        long long cd=min(a[i-1]-a[i],cmi);
        cmi-=cd;
        for(int j=0;j<i;j++){a[j]-=cd;}
      }
      cmi=min(a[i],cmi);
    }
    int res=1;
    for(int i=0;i<(n-1);i++){
      if(a[i]>a[i+1]){res=0;}
    }
    if(res==1){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
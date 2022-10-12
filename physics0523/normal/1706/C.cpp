#include<bits/stdc++.h>

using namespace std;

long long f(int l,int r,vector<long long> &a){
  long long res=0;
  for(int i=l;i<=r;i+=2){
    res+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    if(n%2){
      cout << f(1,n-2,a) << "\n";
    }
    else{
      long long m1=0,m0=0;
      for(int i=1;i<=n-2;i++){
        if(i%2){
          m0=min(m0,m1);
          m1+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
        }
        else{
          m0+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
        }
      }
      cout << min(m0,m1) << "\n";
    }
  }
  return 0;
}
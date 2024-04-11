#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

long long f(long long n){
  return llsankaku(n)+llsankaku(n)+llsankaku(n-1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,res=0;
    cin >> n;
    while(n>=2){
      long long st=1,fi=100000;
      while(st<=fi){
        long long te=(st+fi)/2;
        if(f(te)<=n){st=te+1;}else{fi=te-1;}
      }
      n-=f(fi);
      res++;
    }
    cout << res << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    long long res=0,cv=1;
    while(cv<n){
      if(cv<=k){
        res++;
        cv*=2;
      }
      else{
        long long rem=n-cv;
        res+=llceil(rem,k);
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
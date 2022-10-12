#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

long long f(long long n){
  long long st=1,fi=1000000007;
  while(st<=fi){
    long long te=(st+fi)/2;
    if(n<=llsankaku(te)){fi=te-1;}
    else{st=te+1;}
  }
  return n-llsankaku(fi);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  cout << f(n) << '\n';
  return 0;
}
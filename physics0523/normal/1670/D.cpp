#include<bits/stdc++.h>

using namespace std;

long long f(long long n){
  long long res=0;
  long long p=n/3,q=n%3;
  if(p>=1){
    res=((3+6*p-3)*p)/2;
  }
  long long cur=2*p;
  for(long long i=0;i<q;i++){
    res+=cur;
    cur++;
  }
  return 2*res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long st=1,fi=1e9;
    while(st<=fi){
      long long te=(st+fi)/2;
      if(n<=f(te)){fi=te-1;}
      else{st=te+1;}
    }
    cout << st << '\n';
  }
  return 0;
}
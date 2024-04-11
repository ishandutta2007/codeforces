#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,s;
    cin >> n >> s;
    long long st=0,fi=n+1;
    while(st<=fi){
      long long te=(st+fi)/2;
      long long rem=(n+1)-te;
      long long l=n*n*te;
      long long r=n*n*te+(n-1)*rem;
      if(l<=s && s<=r){cout << te << '\n';break;}
      if(s<l){fi=te-1;}
      else{st=te+1;}
    }
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  long long del=m;
  long long st=0,fi=2.5e9;
  while(st<=fi){
    long long te=(st+fi)/2;
    long long subt=(m+te)+llsankaku(te-1);
    if(n<=subt){fi=te-1;}
    else{st=te+1;}
  }
  cout << min(n,st+del) << '\n';
  return 0;
}
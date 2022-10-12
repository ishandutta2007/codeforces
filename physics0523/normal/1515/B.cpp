#include<bits/stdc++.h>

using namespace std;

bool issq(long long x){
  long long st=0,fi=1000000007,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(te*te==x){return true;}
    if(te*te<x){st=te+1;}
    else{fi=te-1;}
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long v;
    cin >> v;
    bool fl=false;
    if(v%2==0 && issq(v/2)){fl=true;}
    if(v%4==0 && issq(v/4)){fl=true;}
    if(fl){cout << "YES\n";}else{cout <<"NO\n";}
  }
  return 0;
}
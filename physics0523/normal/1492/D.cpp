#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b,k;
  cin >> a >> b >> k;
  b--;
  int ul=max(0,a+b-1);
  if(k>ul){cout << "No\n";return 0;}
  string suf;
  while(max(0,a+b-1)>k){
    if(a>b){
      suf.push_back('0');
      a--;
    }
    else{
      suf.push_back('1');
      b--;
    }
  }
  string r1,r2;
  if(k==0){
    while(a>0){
      r1.push_back('0');
      a--;
    }
    while(b>0){
      r1.push_back('1');
      b--;
    }
    r2=r1;
  }
  else if(a>0 && b>0){
    while(b>0){
      r1.push_back('1');
      b--;
    }
    while(a>0){
      r1.push_back('0');
      a--;
    }
    r2=r1;
    swap(r2[0],r2[r2.size()-1]);
  }
  else{cout << "No\n";return 0;}
  cout << "Yes\n";
  cout << "1" << r1 << suf << '\n';
  cout << "1" << r2 << suf << '\n';
  return 0;
}
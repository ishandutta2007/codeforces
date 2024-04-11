#include<bits/stdc++.h>

using namespace std;

void out_as(int x){
  for(int i=0;i<x;i++){cout << "a";}
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
    if(n==1){cout << "a\n";}
    else if(n==2){cout << "ab\n";}
    else if(n==3){cout << "abc\n";}
    else if(n%2==0){
      int a=(n/2);
      int b=a-1;
      out_as(a);
      cout << "b";
      out_as(b);
      cout << '\n';
    }
    else{
      int a=(n/2);
      int b=a-1;
      out_as(a);
      cout << "bc";
      out_as(b);
      cout << '\n';
    }
  }
  return 0;
}
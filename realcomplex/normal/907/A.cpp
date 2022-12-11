#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  for(int i = 0;i<=200;i++)
    for(int j = i+1;j<=200;j++)
      for(int x = j+1;x<=200;x++)
        if(d<=i and d<=j and d<=x and a<=x and b<=j and c<=i and a*2>=x and a*2>=x and b*2>=j and c*2>=i and d*2>=i and d*2<x and d*2<j){
          cout << x << "\n" << j << "\n" << i;
          return 0;
        }
  cout << -1 << "\n";
  return 0;
}
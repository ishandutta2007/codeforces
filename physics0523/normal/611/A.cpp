#include<bits/stdc++.h>

using namespace std;

int d2016[16]={-1,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  string y,z;
  cin >> x >> y >> z;
  if(z[0]=='w'){
    if(x==5 || x==6){cout << 53 << '\n';}
    else{cout << 52 << '\n';}
  }
  else{
    int res=0;
    for(int i=1;i<=12;i++){
      if(x<=d2016[i]){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}
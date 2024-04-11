#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  if(n>m){swap(n,m);}
  if(n==1){
    long long res=(m/6)*6;
    if(m%6==0){res+=0;}
    if(m%6==1){res+=0;}
    if(m%6==2){res+=0;}
    if(m%6==3){res+=0;}
    if(m%6==4){res+=2;}
    if(m%6==5){res+=4;}
    cout << res << '\n';
  }
  else if(n==2){
    if(m==2){cout << "0\n";}
    else if(m==3){cout << "4\n";}
    else if(m==7){cout << "12\n";}
    else{cout << (n*m) << '\n';}
  }
  else{
    cout << ((n*m)/2)*2 << '\n';
  }
  return 0;
}
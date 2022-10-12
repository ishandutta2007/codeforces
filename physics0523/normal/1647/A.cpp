#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    if(n==1){cout << "1\n";}
    else if(n==2){cout << "2\n";}
    else{
      int len=(n/3)*2,ofs;
      if(n%3){len++;}
      if(n%3==1){ofs=2;}else{ofs=1;}
      for(int i=0;i<len;i++){
        if((ofs+i)%2){cout << "2";}
        else{cout << "1";}
      }
      cout << '\n';
    }
  }
  return 0;
}
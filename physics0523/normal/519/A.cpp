#include<bits/stdc++.h>

using namespace std;

int wei(char c){
  if(c=='Q'){return 9;}
  if(c=='q'){return -9;}
  if(c=='R'){return 5;}
  if(c=='r'){return -5;}
  if(c=='B'){return 3;}
  if(c=='b'){return -3;}
  if(c=='N'){return 3;}
  if(c=='n'){return -3;}
  if(c=='P'){return 1;}
  if(c=='p'){return -1;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  int w=0;
  for(int i=0;i<8;i++){
    cin >> s;
    for(auto &nx : s){
      w+=wei(nx);
    }
  }
  if(w>0){cout << "White\n";}
  else if(w<0){cout << "Black\n";}
  else{cout << "Draw\n";}
  return 0;
}
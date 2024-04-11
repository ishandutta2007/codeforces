#include <bits/stdc++.h>

using namespace std;

int emp[3][3];
char conf[9][9];

int main(){
  for(int i =0;i<9;i++)
    for(int x = 0;x<9;x++){
      cin >> conf[i][x];
      if(conf[i][x]=='.')emp[i/3][x/3]=1;
    } 
  int l,r;
  cin >> l >> r;
  l--;
  r--;
  if(emp[l%3][r%3]){
    for(int i = 0;i<9;i++){
      for(int j = 0;j<9;j++){
        if(i/3==l%3&&j/3==r%3&&conf[i][j]=='.')conf[i][j]='!';
        cout << conf[i][j];
        if(j%3==2)cout << " ";
        //cout << " ";
      }
      if(i%3==2)cout << "\n";
      cout << "\n";
    } 
  }
  else{
    for(int i = 0;i<9;i++){
      for(int j = 0;j<9;j++){
        if(conf[i][j]=='.')conf[i][j]='!';
        cout << conf[i][j];
        if(j%3==2)cout << " ";
      }
      if(i%3==2)cout << "\n";
      cout << "\n";
    }
  }
  return 0;
}
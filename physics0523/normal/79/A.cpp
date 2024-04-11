#include<bits/stdc++.h>

using namespace std;

int dx[3]={2,1,0};
int dy[3]={2,12,22};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x,y;
  cin >> x >> y;
  for(int i=0;;i++){
    int tg=-1;
    if(i%2==0){
      for(int j=0;j<3;j++){
        if(x>=dx[j] && y>=dy[j]){tg=j;break;}
      }
    }
    else{
      for(int j=2;j>=0;j--){
        if(x>=dx[j] && y>=dy[j]){tg=j;break;}
      }
    }
    if(tg==-1){
      if(i%2){cout << "Ciel\n";}
      else{cout << "Hanako\n";}
      return 0;
    }
    x-=dx[tg];
    y-=dy[tg];
  }
  return 0;
}
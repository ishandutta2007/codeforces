#include<bits/stdc++.h>

using namespace std;

int dx4[4]={1,0,-1,0};
int dy4[4]={0,1,0,-1};

int main(){
  int x,y;
  cin >> x >> y;
  if(x==0 && y==0){cout << "0\n";return 0;}
  int res=0,cx=0,cy=0;
  int cur=0;
  while(1){
    for(int i=1;i<=1+(cur/2);i++){
      cx+=dx4[(cur%4)];cy+=dy4[(cur%4)];
      if(cx==x && cy==y){break;}
    }
    if(cx==x && cy==y){break;}
    res++;cur++;
  }
  cout << res << '\n';
}
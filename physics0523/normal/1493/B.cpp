#include<bits/stdc++.h>

using namespace std;

vector<int> mir={0,1,5,-1,-1,2,-1,-1,8,-1};

int f_mir(int x){
  int p=x/10;
  int q=x%10;
  if(mir[p]==-1){return -1;}
  if(mir[q]==-1){return -1;}
  return mir[q]*10+mir[p];
}

pair<int,int> find_mir(int h,int m){
  int rh=f_mir(m),rm=f_mir(h);
  if(rh<0 || rm<0){return {-1,-1};}
  return {rh,rm};
}

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int h,m;
    scanf("%d%d",&h,&m);
    int ch,cm;
    scanf("%d:%d",&ch,&cm);
    while(1){
      pair<int,int> cmir=find_mir(ch,cm);
      if(0<=cmir.first && cmir.first<h && 0<=cmir.second && cmir.second<m){
        printf("%02d:%02d\n",ch,cm);
        break;
      }
      cm++;
      if(cm==m){cm=0;ch++;}
      ch%=h;
    }
  }
  return 0;
}
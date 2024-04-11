#include<bits/stdc++.h>

using namespace std;

int ask(int l,int r){
  printf("? %d %d\n",l,r);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return (r-l+1)-res;
}

void ans(int res){
  printf("! %d\n",res);
  fflush(stdout);
}

int main(){
  int n,t;
  scanf("%d%d",&n,&t);
  while(t>0){
    t--;
    int v;
    scanf("%d",&v);
    int st=1,fi=n,te;
    while(st<=fi){
      te=(st+fi)/2;
      if(ask(1,te)<v){st=te+1;}else{fi=te-1;}
    }
    ans(st);
  }
  return 0;
}
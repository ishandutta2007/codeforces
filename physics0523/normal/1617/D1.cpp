#include<bits/stdc++.h>

using namespace std;

int ask(int a,int b,int c){
  printf("? %d %d %d\n",a+1,b+1,c+1);
  fflush(stdout);

  int res;
  scanf("%d",&res);
  return res;
}

void ans(vector<int> &a){
  printf("! %d",(int)(a.size()));
  for(auto &nx : a){
    printf(" %d",nx+1);
  }
  printf("\n");
  fflush(stdout);

  //int res;
  //scanf("%d",&res);
  //return res;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n;
    scanf("%d",&n);
    vector<int> mem(n);
    for(int i=0;i<n;i++){mem[i]=ask(i,(i+1)%n,(i+2)%n);}
    vector<int> tg;
    for(int i=0;i<n;i++){
      if(mem[i]!=mem[(i+1)%n]){tg.push_back(i);}
      if(tg.size()>=2){break;}
    }

    vector<int> res(n,-1);
    // [o(o[o]o)o]
    if((tg[0]+1)==tg[1]){res[(tg[0]+2)%n]=1-mem[(tg[0]+1)%n];}

    for(int i=0;i<n;i++){
      if(res[i]!=-1){continue;}
      for(int j=0;j<2;j++){
        int b=(tg[j]+1)%n;
        int c=(tg[j]+2)%n;
        if(i==b || i==c){continue;}
        res[i]=ask(i,b,c);
        break;
      }
    }
    vector<int> lis;
    for(int i=0;i<n;i++){
      if(res[i]==0){lis.push_back(i);}
    }
    ans(lis);
  }
  return 0;
}
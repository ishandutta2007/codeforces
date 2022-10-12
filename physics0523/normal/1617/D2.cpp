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
}

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n;
    scanf("%d",&n);

    vector<int> grp(n/3);
    for(int i=0;i<(n/3);i++){
      grp[i]=ask(3*i,3*i+1,3*i+2);
    }

    int zs,os;
    for(int i=1;i<(n/3);i++){
      if(grp[i-1]!=grp[i]){
        int fp=3*(i-1);
        if(grp[i-1]!=ask(fp+1,fp+2,fp+3)){
          if(grp[i-1]==0){zs=fp;os=fp+3;}
          else{zs=fp+3;os=fp;}
        }
        else if(grp[i-1]!=ask(fp+2,fp+3,fp+4)){
          if(grp[i-1]==0){zs=fp+1;os=fp+4;}
          else{zs=fp+4;os=fp+1;}
        }
        else{
          if(grp[i-1]==0){zs=fp+2;os=fp+5;}
          else{zs=fp+5;os=fp+2;}
        }
        break;
      }
    }
    vector<int> res(n,-1);
    res[zs]=0;res[os]=1;
    for(int i=0;i<(n/3);i++){
      if(res[3*i]==-1 && res[3*i+1]==-1 && res[3*i+2]==-1){
        if(grp[i]==0){
          if(ask(os,3*i,3*i+1)==0){
            res[3*i]=0;res[3*i+1]=0;
            res[3*i+2]=ask(zs,os,3*i+2);
          }
          else{
            res[3*i+2]=0;
            res[3*i]=ask(zs,os,3*i);
            res[3*i+1]=1-res[3*i];
          }
        }
        else{
          if(ask(zs,3*i,3*i+1)==1){
            res[3*i]=1;res[3*i+1]=1;
            res[3*i+2]=ask(zs,os,3*i+2);
          }
          else{
            res[3*i+2]=1;
            res[3*i]=ask(zs,os,3*i);
            res[3*i+1]=1-res[3*i];
          }
        }
      }
      else{
        if(res[3*i]==-1){res[3*i]=ask(3*i,zs,os);}
        if(res[3*i+1]==-1){res[3*i+1]=ask(3*i+1,zs,os);}
        if(res[3*i+2]==-1){res[3*i+2]=ask(3*i+2,zs,os);}
      }
    }

    vector<int> ores;
    for(int i=0;i<n;i++){
      if(res[i]==0){ores.push_back(i);}
    }
    ans(ores);
  }
  return 0;
}
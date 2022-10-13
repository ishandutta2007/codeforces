//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#include<iostream>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

using namespace std;

int main(void){
ios::sync_with_stdio(false);
cin.tie(nullptr);
  int i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  int rcnt[3000005];
  int **res=((int**)malloc(sizeof(int*)*3000005));
  int nmv[4096];
  int rc[4096];
  int st,dt,tr,pv;
  char s[4096];
  scanf("%d%d%s",&n,&k,&s);
  s[n]='R';
  w=0;c=0;l=0;
  for(i=n-1;i>=0;i--){
    if(s[i]=='L'){c++;}
    else{
      rc[l]=i;l++;
      w+=c;
    }
  }
  if(w<k){printf("-1\n");return 0;}
  st=0;dt=w-k;tr=0;
  while(tr<k){
    if(rc[st]==(n-1-st)){st++;continue;}
    dt++;i=st;rcnt[tr]=0;pv=-1;
    while(dt>0 && i<l){
      //printf("%d %d",dt,rc[i]);
      if(s[rc[i]+1]=='L' && pv!=rc[i]+1){
        pv=rc[i];
        s[rc[i]]='L';
        s[rc[i]+1]='R';
        nmv[rcnt[tr]]=rc[i];
        rc[i]++;
        rcnt[tr]++;
        dt--;
      }
      i++;
    }
    res[tr]=((int*)malloc(sizeof(int)*rcnt[tr]));
    for(i=0;i<rcnt[tr];i++){
      res[tr][i]=nmv[i];
    }
    tr++;
  }
  if(dt>0){printf("-1\n");return 0;}
  for(i=0;i<k;i++){
    cout << rcnt[i];
    for(j=0;j<rcnt[i];j++){
      cout << ' ';
      cout << res[i][j]+1;
    }
    cout << '\n';
  }
  return 0;
}
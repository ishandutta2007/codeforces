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

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}

using namespace std;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

#define size 16777216

int deque[size],fpt=size/2,bpt=(size/2)+1;

void push(int v,int isbk){
  if(isbk){deque[bpt]=v;bpt++;}
  else{deque[fpt]=v;fpt--;}
}

int pop(int isbk){
  int r;
  if(isbk){bpt--;r=deque[bpt];deque[bpt]=inf;}
  else{fpt++;r=deque[fpt];deque[fpt]=-inf;}
  return r;
}

typedef struct{
  int par;
  int dep;
}node;

node uft[1048576];

void resuf(){
  int i;
  for(i=0;i<1048576;i++){
    uft[i].par=i;uft[i].dep=0;
  }
  return;
}

int find(int x){
  if(uft[x].par==x){return x;}
  else{uft[x].par=find(uft[x].par);return uft[x].par;}
}

void uni(int x,int y){
  int xp,yp;
  xp=find(x);yp=find(y);
  if(xp==yp){return;}
  if(uft[xp].dep>uft[yp].dep){
    uft[yp].par=xp;
  }
  else{
    uft[xp].par=yp;
    if(uft[xp].dep==uft[yp].dep){uft[yp].dep++;}
  }
  return;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int i,j,n,m,k,a,b,c,h,w,r=0,l,q,fl;
  int da,db;
  int ca,cb,ad;
  long long art[1024][1024];
  long long t;
  bool pfl[1024][1024];
  char s[1024][1024],iu;

  scanf("%d%d%d",&n,&m,&q);
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      art[i][j]=llinf;
      pfl[i][j]=false;
      fl=0;
      for(k=0;k<4;k++){
        da=i+dx4[k];if(da<0||da>=n){continue;}
        db=j+dy4[k];if(db<0||db>=m){continue;}
        if(s[i][j]==s[da][db]){fl=1;break;}
      }
      if(fl==1){
        art[i][j]=0;
        push(i*1024+j,0);
      }
    }
  }

  while(fpt+1<bpt){
    ca=pop(0);
    cb=ca%1024;
    ca/=1024;
    if(pfl[ca%1024][cb]){continue;}
    pfl[ca][cb]=true;
    for(k=0;k<4;k++){
      da=ca+dx4[k];if(da<0||da>=n){continue;}
      db=cb+dy4[k];if(db<0||db>=m){continue;}
      if(pfl[da][db]){continue;}
      art[da][db]=llmin(art[da][db],art[ca][cb]+1);
      push(da*1024+db,1);
    }
  }
  
  while(q>0){
    q--;
    scanf("%d%d%lld",&a,&b,&t);
    a--;b--;
    //cout << art[a][b] << '\n';
    if(t<art[a][b]){cout << s[a][b] << '\n';}
    else{
      if(s[a][b]=='1'){c=1;}else{c=0;}
      if((t-art[a][b])%2==1){c++;c%=2;}
      cout << c << '\n';
    }
  }
  
  return 0;
}
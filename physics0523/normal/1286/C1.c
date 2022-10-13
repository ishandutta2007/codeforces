//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int sankaku(int x){return ((1+x)*x)/2;}

int da[1024],db[1024],d=0;
char dc[1024];

void query(int st,int fi){
  int i,j,l,rc,ql,tg,k,os;
  int a,b;
  int bk[128][256]={0};
  char s[128];
  printf("? %d %d\n",st,fi);
  fflush(stdout);
  ql=(fi-st+1);
  rc=sankaku(ql);
  for(i=0;i<rc;i++){
    scanf("%s",s);
    l=strlen(s);
    for(j=0;j<l;j++){
      bk[l][s[j]]++;
    }
  }
  tg=ceil(ql,2);
  tg++;
  for(i=2;i<=tg;i++){
    for(j='a';j<='z';j++){
      bk[i][j]+=bk[i-1][j];
    }
  }
  os=0;
  for(i=2;i<=tg;i++){
    k=sankaku(i);
    a=-1;b=-1;
    for(j='a';j<='z';j++){
      if(bk[i][j]%k!=0){
        if(a==-1){a=j;}
        else{b=j;}
      }
    }
    if(b==-1){b=a;}
    if(a==b){
      da[d]=st+os;
      db[d]=st+os;
      dc[d]=a;
      d++;
      da[d]=fi-os;
      db[d]=fi-os;
      dc[d]=b;
      d++;
    }
    else{
      da[d]=st+os;
      db[d]=fi-os;
      dc[d]=a;
      d++;
      da[d]=st+os;
      db[d]=fi-os;
      dc[d]=b;
      d++;
    }
    os++;

    k--;
    for(j=i;j<=tg;j++){
      bk[j][a]-=k;
      bk[j][b]-=k;
      k+=(i-1);
    }
  }
}

int n;
char res[128]={0};
void solve(){
  int i,j;
  for(i=0;i<d;i++){
    for(j=0;j<d;j++){
      if(res[da[j]]!=0 && res[db[j]]!=0){continue;}
      if(da[j]==db[j]){
        res[da[j]]=dc[j];
      }
      if(res[da[j]]==0 && res[db[j]]==0){continue;}
      if(res[da[j]]==0){
        if(res[db[j]]!=dc[j]){
          res[da[j]]=dc[j];
        }
      }
      if(res[db[j]]==0){
        if(res[da[j]]!=dc[j]){
          res[db[j]]=dc[j];
        }
      }
    }
  }
}

int main(void){
  int i,j;
  scanf("%d",&n);
  query(1,n);
  if(n!=1){query(1,n-1);}
  if(n>=3){query(1,1);}
  solve();
  printf("! %s\n",&res[1]);
  fflush(stdout);
  return 0;
}
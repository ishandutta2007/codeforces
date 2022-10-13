#include<stdio.h>
#include<stdbool.h>
#define ssize 1048576

int max(int a,int b){if(a>b){return a;}return b;}

typedef struct{
  //str[0] = prefix
  //str[1] = suffix
  //str[][0] = >>>>
  //str[][1] = <<<<
  int str[2][2];
  int res;
  int dvd;
}stnode;

stnode stree[2*ssize][2],vd;
int fl[2*ssize];

void stnpr(stnode x,int br){
  printf("<%d %d %d %d %d : %d>",x.str[0][0],x.str[0][1],x.str[1][0],x.str[1][1],x.dvd,x.res);
  if(br){printf("\n");}
}

stnode merge(stnode l,stnode r){
  stnode res;
  //stnpr(l,0);printf("+");stnpr(r,1);
  res.res=max(l.res,r.res);
  if(l.dvd==1&&r.dvd==1){
    res.str[0][0]=l.str[0][0];
    res.str[0][1]=l.str[0][1];
    if(l.str[1][1]!=0 && r.str[0][0]!=0){
      res.res=max(max(l.str[1][0]+l.str[1][1],r.str[0][0]+r.str[0][1]),res.res);
    }
    else{
      res.res=max(l.str[1][0]+l.str[1][1]+r.str[0][0]+r.str[0][1],res.res);
    }
    res.str[1][0]=r.str[1][0];
    res.str[1][1]=r.str[1][1];
    res.dvd=1;
  }
  else if(l.dvd==1&&r.dvd==0){
    res.str[0][0]=l.str[0][0];
    res.str[0][1]=l.str[0][1];
    if(l.str[1][1]!=0 && r.str[0][0]!=0){
      res.res=max(l.str[1][0]+l.str[1][1],res.res);
      res.str[1][0]=r.str[0][0];
      res.str[1][1]=r.str[0][1];
    }
    else{
      res.str[1][0]=l.str[1][0]+r.str[0][0];
      res.str[1][1]=l.str[1][1]+r.str[0][1];
    }
    res.dvd=1;
  }
  else if(l.dvd==0&&r.dvd==1){
    if(l.str[0][1]!=0 && r.str[0][0]!=0){
      res.res=max(r.str[0][0]+r.str[0][1],res.res);
      res.str[0][0]=l.str[0][0];
      res.str[0][1]=l.str[0][1];
    }
    else{
      res.str[0][0]=l.str[0][0]+r.str[0][0];
      res.str[0][1]=l.str[0][1]+r.str[0][1];
    }
    res.str[1][0]=r.str[1][0];
    res.str[1][1]=r.str[1][1];
    res.dvd=1;
  }
  else{
    if(l.str[0][1]!=0&&r.str[0][0]!=0){
      res.str[0][0]=l.str[0][0];
      res.str[0][1]=l.str[0][1];
      res.str[1][0]=r.str[0][0];
      res.str[1][1]=r.str[0][1];
      res.dvd=1;
    }
    else{
      res.str[0][0]=l.str[0][0]+r.str[0][0];
      res.str[0][1]=l.str[0][1]+r.str[0][1];
      res.str[1][0]=0;
      res.str[1][1]=0;
      res.dvd=0;
    }
  }
  //stnpr(res,1);
  return res;
}

void stinit(){
  int i;
  for(i=(ssize-2);i>=0;i--){
    stree[i][0]=merge(stree[i*2+1][0],stree[i*2+2][0]);
    stree[i][1]=merge(stree[i*2+1][1],stree[i*2+2][1]);
  }
  for(i=0;i<2*ssize;i++){
    fl[i]=0;
  }
}

void eval(int k){
  if(fl[k]%2==1){
    //printf("rev %d\n",k);
    stnode c;
    c=stree[k][0];
    stree[k][0]=stree[k][1];
    stree[k][1]=c;
    if(k<(ssize-1)){
      fl[k*2+1]++;
      fl[k*2+2]++;
    }
  }
  fl[k]=0;
}

void revquery(int a,int b,int k,int l,int r){
  eval(k);
  if(r<=a || b<=l){return;}
  if(a<=l && r<=b){
    fl[k]++;
    eval(k);
    return;
  }
  else{
    eval(k*2+1);
    eval(k*2+2);
    revquery(a,b,k*2+1,l,(l+r)/2);
    revquery(a,b,k*2+2,(l+r)/2,r);
    stree[k][0]=merge(stree[k*2+1][0],stree[k*2+2][0]);
    stree[k][1]=merge(stree[k*2+1][1],stree[k*2+2][1]);
    fl[k]=0;
  }
}

stnode getquery(int a,int b,int k,int l,int r){
  //printf("call %d : [%d , %d) vs [%d , %d)\n",k,l,r,a,b);
  eval(k);
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){
    //printf("%d back:<%d %d %d %d %d : %d>\n",k,stree[k][0].str[0][0],stree[k][0].str[0][1],stree[k][0].str[1][0],stree[k][0].str[1][1],stree[k][0].dvd,stree[k][0].res);
    return stree[k][0];
  }
  stnode ld,rd;
  ld=getquery(a,b,k*2+1,l,(l+r)/2);
  rd=getquery(a,b,k*2+2,(l+r)/2,r);
  //printf("%d l:<%d %d %d %d %d : %d>\n",k,ld.str[0][0],ld.str[0][1],ld.str[1][0],ld.str[1][1],ld.dvd,ld.res);
  //printf("%d r:<%d %d %d %d %d : %d>\n",k,rd.str[0][0],rd.str[0][1],rd.str[1][0],rd.str[1][1],rd.dvd,rd.res);
  return merge(ld,rd);
}

int main(){
  vd.str[0][0]=0;vd.str[0][1]=0;
  vd.str[1][0]=0;vd.str[1][1]=0;
  vd.res=0;vd.dvd=0;
  stnode tl,tr;
  tl.str[0][0]=0;tl.str[0][1]=1;
  tl.str[1][0]=0;tl.str[1][1]=0;
  tl.res=0;tl.dvd=0;
  tr.str[0][0]=1;tr.str[0][1]=0;
  tr.str[1][0]=0;tr.str[1][1]=0;
  tr.res=0;tr.dvd=0;
  int n,q,i;
  int l,r,ans;
  stnode res;
  char s[ssize];
  scanf("%d%d%s",&n,&q,&s[1]);
  for(i=0;i<2*ssize;i++){
    stree[i][0]=vd;
    stree[i][1]=vd;
  }
  for(i=1;i<=n;i++){
    if(s[i]=='<'){
      stree[i+(ssize-1)][0]=tl;
      stree[i+(ssize-1)][1]=tr;
    }
    else{
      stree[i+(ssize-1)][0]=tr;
      stree[i+(ssize-1)][1]=tl;
    }
  }
  stinit();
  while(q>0){
    q--;
    scanf("%d%d",&l,&r);
    revquery(l,r+1,0,0,ssize);
    res=getquery(l,r+1,0,0,ssize);
    //stnpr(res,1);
    ans=max(res.str[0][0]+res.str[0][1],res.str[1][0]+res.str[1][1]);
    ans=max(res.res,ans);
    printf("%d\n",ans);
  }
  return 0;
}
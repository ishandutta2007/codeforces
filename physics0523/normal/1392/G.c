#include<stdio.h>
#include<stdbool.h>

int max(int a,int b){if(a>b){return a;}return b;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}

int pkbt(int fl,int p){
  if(fl&(1<<p)){return 1;}
  return 0;
}

int n,m,k;
int res[1048576];
int rp[1048576];
void rrep(int fl,int cv,int tag){
  if(res[fl]>=cv){return;}
  res[fl]=cv;
  rp[fl]=tag;
  int i;
  for(i=0;i<k;i++){rrep(fl^(1<<i),cv-1,tag);}
}

int main(){
  int i,j;
  for(i=0;i<1048576;i++){res[i]=-1;}
  int sv=0,tv=0,r=-1;
  char s[32],t[32];
  int a[1048576],b[1048576];
  int pm[1048576][32];
  int mem[32],gv;
  int rf,rt;
  
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s%s",s,t);
  for(i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
    a[i]--;b[i]--;
  }
  for(i=0;i<k;i++){
    pm[n][i]=i;
    if(s[i]=='1'){sv+=(1<<i);}
    if(t[i]=='1'){tv+=(1<<i);}
  }
  for(i=n-1;i>=0;i--){
    //printf("<%d>",i);
    for(j=0;j<k;j++){pm[i][j]=pm[i+1][j];}
    swap(&pm[i][a[i]],&pm[i][b[i]]);
    if((i+m)<=n){
      gv=0;
      for(j=0;j<k;j++){
        if(tv&(1<<j)){gv+=(1<<pm[i+m][j]);}
      }
      rrep(gv,k,i+m);//printf("%d %d %d\n",gv,k,i+m);
      gv=0;
      for(j=0;j<k;j++){
        if(sv&(1<<j)){gv+=(1<<pm[i][j]);}
      }
      //printf("%d\n",res[gv]);
      if(r<res[gv]){
        r=res[gv];
        rf=i+1;
        rt=rp[gv];
      }
    }
  }
  printf("%d\n%d %d\n",r,rf,rt);
}
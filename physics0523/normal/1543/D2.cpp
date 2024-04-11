#include<bits/stdc++.h>

using namespace std;

int query(int x){
  printf("%d\n",x);
  fflush(stdout);
  int v;
  scanf("%d",&v);
  return v;
}

int k;
int kxor(int a,int b){
  int c=0,v=1;
  while(a>0 || b>0){
    int d=(a+b)%k;
    c+=v*d;
    a/=k;b/=k;v*=k;
  }
  return c;
}

int kxormt(int a,int tim){
  tim%=k;
  int c=0,v=1;
  while(a>0){
    int d=(a*tim)%k;
    c+=v*d;
    a/=k;v*=k;
  }
  return c;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n;
    scanf("%d%d",&n,&k);
    int ef=0;
    int pt=1;
    for(int i=0;i<n;i++){
      int ask=kxor(kxormt(i,pt),ef);
      if(query(ask)){break;}
      pt*=(k-1);pt%=k;
      ef=kxormt(ef,(k-1));
      ef=kxor(ef,ask);
    }
  }
  return 0;
}
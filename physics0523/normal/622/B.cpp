#include<bits/stdc++.h>

using namespace std;

int main(){
  int h,m;
  scanf("%d:%d",&h,&m);
  int w;
  scanf("%d",&w);
  w%=1440;
  m+=w;

  h+=(m/60);
  m%=60;
  h%=24;
  printf("%02d:%02d\n",h,m);
  return 0;
}
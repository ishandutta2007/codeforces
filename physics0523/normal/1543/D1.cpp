#include<bits/stdc++.h>

using namespace std;

int query(int x){
  printf("%d\n",x);
  fflush(stdout);
  int v;
  scanf("%d",&v);
  return v;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n,k;
    scanf("%d%d",&n,&k);
    int ef=0;
    for(int i=0;i<n;i++){
      if(query(i^ef)){break;}
      ef^=(i^ef);
    }
  }
  return 0;
}
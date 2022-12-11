#include <bits/stdc++.h>

using namespace std;

int v[105];

int main(){
  int n,q;
  scanf("%i %i",&n,&q);
  int ti,k,len;
  int cnt = 0;
  int l;
  for(int j = 0;j<q;j++){
    scanf("%i %i %i",&ti,&k,&len);
    cnt = 0;
    for(int i = 1;i<=n;i++){
      if(v[i]<=ti)
        cnt++;
    }
    if(cnt<k){
      printf("-1\n");
      continue;
    }
    cnt=0;
    l=0;
    for(int i = 1;i<=n;i++){
      if(v[i]<=ti){
        cnt++;
        l+=i;
        v[i]=ti+len;
        if(cnt==k)break;
      }
    }
    printf("%i\n",l);
  } 
  return 0;  
}
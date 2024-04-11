#include <bits/stdc++.h>

using namespace std;

int ans;

int check(int l,int r){
  int cnt[10][2];
  for(int i = 0;i<10;i++)
    cnt[i][0]=0,cnt[i][1]=0;
  while(l>0)cnt[l%10][0]++,l/=10;
  while(r>0)cnt[r%10][1]++,r/=10;
  for(int i = 0;i<10;i++)
    if(cnt[i][0]>0 and cnt[i][1]>0)
      return 1;
  return 0;
}

void divisor(int n){
  for(int i = 1;i*i<=n;i++){
    if(n%i==0){
      ans+=check(i,n);
      if(n/i!=i){
        ans+=check(n/i,n);
      }
    }
  }
}

int main(){
  int n;
  scanf("%d",&n);
  divisor(n);
  printf("%d\n",ans);
  return 0;
}
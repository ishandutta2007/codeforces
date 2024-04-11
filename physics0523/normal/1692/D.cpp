#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int h,m,x;
    scanf("%d:%d %d\n",&h,&m,&x);
    int res=0;
    x=gcd(60*24,x);
    for(int i=0;i<60*24;i+=x){
      if(h/10==m%10 && h%10==m/10){res++;}
      m+=x;
      if(m>=60){h+=(m/60);m%=60;}
      h%=24;
    }
    cout << res << '\n';
  }
  return 0;
}
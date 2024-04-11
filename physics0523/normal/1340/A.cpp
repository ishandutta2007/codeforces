#include<bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,n,m,k,a[524288],b[524288],tg,st,p,fl,t;
  scanf("%d",&t);
  while(t>0){
    t--;fl=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&a[i]);
      b[a[i]]=i;
    }
    for(i=2;i<=n;i++){
      if(b[i-1]+1<b[i]){fl=0;break;}
    }
    tg=n;st=1;
    for(i=2;i<=n;i++){
      if(b[i-1]>b[i]){
        if(b[i-1]!=tg){fl=0;break;}
        tg=b[st]-1;
        st=i;
      }
    }
    if(fl==1){cout << "Yes" << '\n';}
    else{cout << "No" << '\n';}
  }
  return 0;
}
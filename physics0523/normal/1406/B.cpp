#include<bits/stdc++.h>

using namespace std;

int main(){
  long long t,n;
  scanf("%lld",&t);
  while(t>0){
    t--;
    long long res=-9000000000000000000;
    scanf("%lld",&n);
    vector<long long> a;
    for(int i=0;i<n;i++){
      long long v;
      scanf("%lld",&v);
      if(v!=0){a.push_back(v);}
      else{res=0;}
    }
    if(a.size()<5){puts("0");continue;}
    sort(a.begin(),a.end());
    n=a.size();
    for(int i=0;i<n;i++){
      if(i>=20 && i+20<n){continue;}
      for(int j=i+1;j<n;j++){
        if(j>=20 && j+20<n){continue;}
        for(int k=j+1;k<n;k++){
          if(k>=20 && k+20<n){continue;}
          for(int l=k+1;l<n;l++){
            if(l>=20 && l+20<n){continue;}
            for(int m=l+1;m<n;m++){
              if(m>=20 && m+20<n){continue;}
              res=max(a[i]*a[j]*a[k]*a[l]*a[m],res);
            }
          }
        }
      }
    }
    printf("%lld\n",res);
  }
  return 0;
}
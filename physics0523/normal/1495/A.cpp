#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n;
    scanf("%d",&n);
    vector<long long> a,b;
    for(int i=0;i<2*n;i++){
      long long p,q;
      scanf("%lld%lld",&p,&q);
      if(p==0){a.push_back(q*q);}
      else{b.push_back(p*p);}
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    double res=0.0;
    for(int i=0;i<n;i++){
      res+=sqrt((double)(a[i]+b[i]));
    }
    printf("%.12lf\n",res);
  }
  return 0;
}
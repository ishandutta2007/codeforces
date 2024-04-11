#include <bits/stdc++.h>
using namespace std;

int64_t Q=998244353;
int64_t zero=0;

int64_t jyo(int64_t x,int64_t y,int64_t z){
  int64_t H=y; //
       int64_t a=1,b=x,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
}

int main() {
  vector<int64_t> j(200005);
  for(int i=1;i<200005;i++){
    j[i]=jyo(i,Q-2,Q);
  }
  int N,K;
  cin>>N>>K;
  vector<int64_t> p(N+1);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  p[N]=Q*167;
  sort(p.begin(),p.end());
  vector<int64_t> rui(N+1);
  for(int i=0;i<N;i++){
    rui[i+1]=rui[i]+p[i];
    rui[i+1]%=Q;
  }
  for(int i=0;i<K;i++){
    int64_t a,b;
    cin>>a>>b;
    int64_t s,u;
    s=lower_bound(p.begin(),p.end(),b)-p.begin();
    u=N-s;
    int64_t A=max(u-a,zero),C=max(u-a+1,zero);
    int64_t Z;
    Z=(((rui[N]-rui[s]+Q)%Q)*((A*j[u])%Q))%Q;
    Z+=(rui[s]*((C*j[u+1])%Q))%Q;
    Z%=Q;
    cout<<Z<<endl;
  }
}
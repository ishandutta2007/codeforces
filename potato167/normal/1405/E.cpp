#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144*2;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return 0;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    return X+Y;
  }
}
void pu(int64_t a,int b){
  int D=MAX_N-1+b;
  while(D>0){
    seg[D]+=a;
    D--;
    D/=2;
  }
  seg[0]+=a;
}

int main() {
  int N,Q;
  cin>>N>>Q;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p[i]=i+1-a;
  }
  vector<tuple<int,int,int>> q(Q);
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    b=N-b;
    q[i]=make_tuple(b,a,i);
  }
  sort(q.begin(),q.end());
  int T=0;
  vector<int> ans(Q);
  for(int k=0;k<Q;k++){
    int b,a,c;
    tie(b,a,c)=q[k];
    for(int i=T;i<b;i++){
      if(p[i]<0){
        continue;
      }
      if(p[i]==0){
        pu(1,i);
      }
      else{
        if(qu(0,i,0,0,MAX_N)<p[i]){
          continue;
        }
        int l=0,r=i;
        while(r-l>1){
          int D=(l+r)/2;
          if(qu(D,i,0,0,MAX_N)>=p[i]){
            l=D;
          }
          else{
            r=D;
          }
        }
        pu(1,l);
      }
    }
    T=b;
    ans[c]=qu(a,b,0,0,MAX_N);
  }
  for(int i=0;i<Q;i++){
    cout<<ans[i]<<endl;
  }
}
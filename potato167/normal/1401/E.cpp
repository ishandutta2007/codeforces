#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144*4;
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
  int n,m;
  cin>>n>>m;
  vector<tuple<int,int,int,int>> sen(n+m);
  int64_t Z=1;
  for(int i=0;i<n+m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(b==0&&c==1000000){
      Z++;
    }
    if(i<n){
      sen[i]=make_tuple(a,max(1,b),c,0);
    }
    else if(b==0){
      sen[i]=make_tuple(c+1,0,0,a);
      pu(1,a);
    }
    else{
      sen[i]=make_tuple(b,0,0,a*-1);
    }
  }
  sort(sen.begin(),sen.end());
  for(int i=0;i<n+m;i++){
    int a,b,c,d;
    tie(a,b,c,d)=sen[i];
    if(d==0){
      Z+=qu(b,c+1,0,0,MAX_N);
    }
    else if(d<0){
      d*=-1;
      pu(1,d);
    }
    else{
      pu(-1,d);
    }
  }
  cout<<Z<<endl;
  
}
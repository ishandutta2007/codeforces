#include<bits/stdc++.h>

using namespace std;

int pack(int p,int q,int r){
  return p*128*128+q*128+r;
}

void unpack(int &p,int &q,int &r,int s){
  r=s%128;s/=128;
  q=s%128;s/=128;
  p=s;
}

typedef struct{
  double p;
  double q;
  double r;
}data;

int main(){
  vector<data> dp(2097152);
  for(int i=1;i<2097152;i++){
    int p,q,r;
    unpack(p,q,r,i);
    if(p==0 && q==0){dp[i].p=0.0;dp[i].q=0.0;dp[i].r=1.0;}
    else if(p==0 && r==0){dp[i].p=0.0;dp[i].q=1.0;dp[i].r=0.0;}
    else if(q==0 && r==0){dp[i].p=1.0;dp[i].q=0.0;dp[i].r=0.0;}
    else{
      double bb=p*q+p*r+q*r;
      dp[i].p=0.0;dp[i].q=0.0;dp[i].r=0.0;
      if(p*q!=0){
        double ce=p*q;ce/=bb;
        data nx=dp[pack(p,q-1,r)];
        dp[i].p+=nx.p*ce;
        dp[i].q+=nx.q*ce;
        dp[i].r+=nx.r*ce;
      }
      if(p*r!=0){
        double ce=p*r;ce/=bb;
        data nx=dp[pack(p-1,q,r)];
        dp[i].p+=nx.p*ce;
        dp[i].q+=nx.q*ce;
        dp[i].r+=nx.r*ce;
      }
      if(q*r!=0){
        double ce=q*r;ce/=bb;
        data nx=dp[pack(p,q,r-1)];
        dp[i].p+=nx.p*ce;
        dp[i].q+=nx.q*ce;
        dp[i].r+=nx.r*ce;
      }
    }
  }
  int p,q,r;
  cin >> p >> q >> r;
  int id=pack(p,q,r);
  printf("%.12lf %.12lf %.12lf\n",dp[id].p,dp[id].q,dp[id].r);
  return 0;
}
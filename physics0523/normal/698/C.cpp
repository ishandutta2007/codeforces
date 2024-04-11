#include<bits/stdc++.h>

using namespace std;

int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}

double dp[1048576]={0.0};

int main(){
  int n,k;
  cin >> n >> k;
  vector<double> p(n);
  double keep=1.0e-9;
  for(auto &nx : p){
    cin >> nx;
    nx*=(1.0-keep);
  }
  for(auto &nx : p){
    nx+=(keep/(double)n);
  }

  dp[0]=1.0;
  for(int i=0;i<(1<<n);i++){
    double sig=0.0;
    for(int j=0;j<n;j++){
      if((i&(1<<j))==0){sig+=p[j];}
    }
    for(int j=0;j<n;j++){
      if((i&(1<<j))==0){
        dp[i|(1<<j)]+=dp[i]*(p[j]/sig);
      }
    }
  }

  vector<double> res(n);
  for(int i=0;i<(1<<n);i++){
    if(dsumb(i,2)==k){
      for(int j=0;j<n;j++){
        if(i&(1<<j)){res[j]+=dp[i];}
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i){printf(" ");}
    if(p[i]<0.005){printf("0.0");}
    else{printf("%.12lf",res[i]);}
  }printf("\n");
  return 0;
}
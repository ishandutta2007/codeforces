#include<bits/stdc++.h>

using namespace std;

int main(){
  int a[100];
  for(int i=0;i<100;i++){
    cin >> a[i];
  }
  vector<int> v;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      int p;
      if(i%2){p=9-j;}
      else{p=j;}
      v.push_back(10*i+p);
    }
  }
  double dp[100],rdp[100];
  dp[0]=0.0;
  rdp[0]=0.0;
  for(int i=1;i<100;i++){
    double div,dlt;
    div=min(6.0,(double)i);
    dlt=(6.0/div);
    //cout << v[i] << ',';
    dp[v[i]]=0.0;
    for(int j=1;j<=6;j++){
      if(i-j<0){continue;}
      dp[v[i]]+=dp[v[i-j]];
    }
    dp[v[i]]/=div;
    dp[v[i]]+=dlt;
    rdp[v[i]]=dp[v[i]];
    dp[v[i]]=min(dp[v[i]],rdp[v[i]-10*a[v[i]]]);
  }
  printf("%.12lf\n",dp[90]);
  return 0;
}
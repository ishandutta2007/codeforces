#include<bits/stdc++.h>

using namespace std;

#define SUM_SIZE 1024

long long sum[SUM_SIZE][SUM_SIZE]={0};

long long ask(int fx,int fy,int tx,int ty){
    if(fx>tx || fy>ty){return 0;}
    if(fx==0 && fy == 0){return sum[tx][ty];}
    else if(fx==0){
        return sum[tx][ty]-sum[tx][fy-1];
    }
    else if(fy==0){
        return sum[tx][ty]-sum[fx-1][ty];
    }
    else{
        return sum[tx][ty]-sum[tx][fy-1]-sum[fx-1][ty]+sum[fx-1][fy-1];
    }
}

void init(){
  for(int i=0;i<SUM_SIZE;i++){
    for(int j=0;j<SUM_SIZE;j++){sum[i][j]=0;}
  }
}

void work(){
  for(int i=0;i<SUM_SIZE;i++){
    for(int j=1;j<SUM_SIZE;j++){sum[i][j]+=sum[i][j-1];}
  }
  for(int i=1;i<SUM_SIZE;i++){
    for(int j=0;j<SUM_SIZE;j++){sum[i][j]+=sum[i-1][j];}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    init();

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
      int p,q;
      cin >> p >> q;
      sum[p][q]+=(p*q);
    }

    work();
    for(int i=0;i<m;i++){
      int fx,fy,tx,ty;
      cin >> fx >> fy >> tx >> ty;
      fx++;fy++;
      tx--;ty--;
      cout << ask(fx,fy,tx,ty) << "\n";
    }
  }
  return 0;
}
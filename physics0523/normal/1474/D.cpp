#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> la(n),ra(n);
    long long cur;
    cur=a[0];
    for(int i=0;i<n;i++){
      la[i]=cur;
      if(i==n-1){break;}
      if(cur!=-1){
        cur=a[i+1]-cur;
        if(cur<0){cur=-1;}
      }
    }
    cur=a[n-1];
    for(int i=n-1;i>=0;i--){
      ra[i]=cur;
      if(i==0){break;}
      if(cur!=-1){
        cur=a[i-1]-cur;
        if(cur<0){cur=-1;}
      }
    }

    bool isok=false;
    if(ra[0]==0){isok=true;}
    for(int i=0;i<n-1;i++){
      vector<long long> suba(4,0);
      suba[1]=a[i+1];
      suba[2]=a[i];
      if((i-1)>=0){
        if(la[i-1]==-1){continue;}
        suba[0]=la[i-1];
      }
      if((i+2)<n){
        if(ra[i+2]==-1){continue;}
        suba[3]=ra[i+2];
      }
      for(int i=0;i<3;i++){
        long long mi=min(suba[i],suba[i+1]);
        suba[i]-=mi;suba[i+1]-=mi;
      }
      for(int i=0;i<4;i++){
        if(suba[i]){break;}
        if(i==3){isok=true;}
      }
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

void div(long long x,vector<long long> &dv){
  for(long long i=2;i*i<=x;i++){
    int tim=0;
    while(x%i==0){x/=i;tim++;}
    if(tim>0){
      int sz=dv.size();
      for(int tg=0;tg<sz;tg++){
        long long ad=dv[tg];
        for(int k=1;k<=tim;k++){
          ad*=i;
          dv.push_back(ad);
        }
      }
    }
  }
  if(x!=1){
    int tim=1;
    int sz=dv.size();
    for(int tg=0;tg<sz;tg++){
      long long ad=dv[tg];
      for(int k=1;k<=tim;k++){
        ad*=x;
        dv.push_back(ad);
      }
    }
  }
}

long long findmult(long long k,long long mi,long long ma){
  long long res=(ma/k)*k;
  if(mi<=res && res<=ma){return res;}
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<long long> dv={1};
    div(a,dv);
    div(b,dv);
    bool ok=false;

    for(auto &nx : dv){
      long long x=nx;
      long long y=(a*b)/nx;
      x=findmult(x,a+1,c);
      y=findmult(y,b+1,d);
      if(x!=-1 && y!=-1){
        ok=true;
        cout << x << " " << y << "\n";
        break;
      }
    }
    if(!ok){cout << "-1 -1\n";}
  }
  return 0;
}
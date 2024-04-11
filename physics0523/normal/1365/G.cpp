#include<bits/stdc++.h>

using namespace std;

long long ask(vector<long long> &a){
  if(a.empty()){return 0;}
  cout << "? " << a.size();
  for(auto &nx : a){
    cout << ' ' << nx+1;
  }cout << '\n';
  fflush(stdout);
  long long res;
  cin >> res;
  return res;
}

void ans(vector<long long> &a){
  cout << "!";
  for(auto &nx : a){
    cout << ' ' << nx;
  }cout << '\n';
  fflush(stdout);
}

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

pair<long long,vector<long long>> findmask(long long n){
  for(long long bn=1;;bn++){
    if(llnCr(bn,(bn/2))<n){continue;}
    vector<long long> res;
    for(long long j=0;(j<(1<<bn) && res.size()<n);j++){
      if(popcount((unsigned long long)j)==(bn/2)){res.push_back(j);}
    }
    return {bn,res};
  }
}

int main(){
  long long n;
  cin >> n;
  pair<long long,vector<long long>> mp=findmask(n);
  vector<long long> qr;
  for(long long tg=0;tg<mp.first;tg++){
    vector<long long> askv;
    for(long long i=0;i<n;i++){
      if(mp.second[i]&(1ll<<tg)){askv.push_back(i);}
    }
    qr.push_back(ask(askv));
  }
  vector<long long> res;
  for(long long i=0;i<n;i++){
    long long v=0;
    for(long long j=0;j<mp.first;j++){
      if(mp.second[i]&(1ll<<j)){continue;}
      v|=qr[j];
    }
    res.push_back(v);
  }
  ans(res);
  return 0;
}
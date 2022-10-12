#include<bits/stdc++.h>

using namespace std;

long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}

vector<long long> luck;
set<long long> luck_set;
void genluck(){
  for(int dg=1;dg<=10;dg++){
    for(int i=0;i<(1<<dg);i++){
      long long v=0;
      for(int j=0;j<dg;j++){
        v*=10;
        if(i&(1<<j)){v+=7;}
        else{v+=4;}
      }
      luck.push_back(v);
    }
  }
  sort(luck.begin(),luck.end());
  for(auto &nx : luck){luck_set.insert(nx);}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  genluck();
  long long n,k;
  cin >> n >> k;
  if(n<=13 && llfact(n)<k){
    cout << "-1\n";
    return 0;
  }
  k--;
  long long suf=min(n,13ll);
  long long res=0;
  long long pre=n-suf;
  for(auto &nx : luck){
    if(nx<=pre){res++;}
  }
  vector<long long> sel;
  for(long long i=1;i<=suf;i++){sel.push_back(pre+i);}
  for(long long i=1;i<=suf;i++){
    long long pos=pre+i;
    long long tg=k/llfact(suf-i);
    k%=llfact(suf-i);
    vector<long long> nsel;
    long long val;
    for(long long j=0;j<sel.size();j++){
      if(j==tg){val=sel[j];}
      else{nsel.push_back(sel[j]);}
    }
    sel=nsel;
    if(luck_set.find(pos)!=luck_set.end() && luck_set.find(val)!=luck_set.end()){
      res++;
    }
  }
  cout << res << '\n';
  return 0;
}
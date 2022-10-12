#include<bits/stdc++.h>

using namespace std;

long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}

long long cnt(long long n,long long lim){
  long long rem=n%lim;
  return (n/lim)+lldsumb(rem,2);
}

int main(){
  long long n,k,del=0,lim=1000000007;
  cin >> n >> k;
  if(lldsumb(n,2)>k){cout << "No\n";return 0;}
  cout << "Yes\n";
  bool fl=false;
  vector<long long> res;

  while(k>0 && n!=0){
    //cout << n << ' ' << k << '\n';
    while(n<k){del--;n*=2;}
    long long tg;
    if(fl){
      tg=0;
      for(long long i=lim-del;i>=0;i--){
        if(i>=62 || n-(1ll<<i)<0){continue;}
        if(1+cnt(n-(1ll<<i),(1ll<<i))<=k){tg=i;break;}
      }
    }
    else{
      for(long long i=0;;i++){
        if(1+cnt(n-(1ll<<i),(1ll<<i))<=k){tg=i;break;}
      }
    }
    n-=(1ll<<tg);k--;
    res.push_back(tg+del);
    fl=true;
    lim=(tg+del);
  }
  int pt=res.size();
  while(k>0){
    long long el=res[pt-1];
    el--;k--;
    res[pt-1]--;
    pt++;
    res.push_back(el);
  }
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long n,k;
vector<long long> a;
long long sig=0,rz=0;

long long sol(){
  long long res=0;
  for(int i=0;i<=n;i++){
    long long cma=0,cmi=0;
    long long rems=sig,remz=rz;
    long long cp=0;
    for(int j=0;j<n;j++){
      cp+=a[j];rems-=a[j];
      if(a[j]==0){
        if(j<i){cp+=k;}
        else{cp-=k;}
        remz--;
      }
      cp=min(remz*k-rems,cp);
      cp=max(-remz*k-rems,cp);
      //cerr<<cp<<' ';
      cma=max(cma,cp);cmi=min(cmi,cp);
    }//cerr << '\n';
    res=max(res,cma-cmi+1);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
    if(nx==0){rz++;}
  }
  if(abs(sig)>k*rz){
    cout << "-1\n";
    return 0;
  }
  long long res=0;
  res=max(res,sol());
  for(auto &nx : a){nx*=-1;}sig*=-1;
  res=max(res,sol());
  cout << res << '\n';
  return 0;
}
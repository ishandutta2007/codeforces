#include<bits/stdc++.h>

using namespace std;

long long n,a,r,m;
vector<long long> h;

long long f(long long tg){
  long long at=0,rt=0;
  for(auto &nx : h){
    if(nx<tg){at+=(tg-nx);}
    else{rt+=(nx-tg);}
  }
  long long mt=min(at,rt);
  at-=mt;rt-=mt;
  return a*at+r*rt+m*mt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a >> r >> m;
  m=min(m,a+r);
  h.resize(n);
  for(auto &nx : h){cin >> nx;}
  long long res=1e18;
  long long st=0,fi=1e9+7;
  while(fi-st>=5){
    long long te1=(2*st+fi)/3;
    long long te2=(st+2*fi)/3;
    long long f1=f(te1);
    long long f2=f(te2);
    if(f1>f2){res=min(res,f2);st=te1+1;}
    else{res=min(res,f1);fi=te2-1;}
  }
  for(long long i=st;i<=fi;i++){
    res=min(res,f(i));
  }
  cout << res << '\n';
  return 0;
}
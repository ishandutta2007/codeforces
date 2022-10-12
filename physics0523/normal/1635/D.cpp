#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

//(1,1,2,3,5,8...) (1-indexed)
long long fib(long long n){
  long long f1=1,f=1;
  long long r1=1,r=0;
  while(n>0){
    if(n&1ll){
      long long nr1,nr;
      nr1=f1*r1+f*r;nr=f1*r+f*(mod+r1-r);
      r1=nr1%mod;r=nr%mod;
    }
    long long nf1,nf;
    nf1=f1*f1+f*f;nf=f*(mod+2*f1-f);
    f1=nf1%mod;f=nf%mod;
    n>>=1;
  }
  return r;
}

int bnum(int x){
  int c=0;
  while(x>0){c++;x>>=1;}
  return c;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,p;
  cin >> n >> p;
  vector<int> a(n);
  set<int> st;
  for(auto &nx : a){
    cin >> nx;
    st.insert(nx);
  }
  vector<int> lis;
  for(auto &nx : a){
    int zc=0;
    bool van=false;
    for(int tg=0;tg<31;tg++){
      if(nx&(1<<tg)){
        if(zc%2==1){break;}
        zc=0;
        if(st.find(nx>>(tg+1))!=st.end()){van=true;break;}
      }
      else{
        zc++;
        if(zc%2==0){
          if(st.find(nx>>(tg+1))!=st.end()){van=true;break;}
        }
      }
    }
    if(!van){lis.push_back(nx);}
  }
  long long res=0;
  for(auto &nx : lis){
    int bc=p-bnum(nx);
    if(bc<0){continue;}
    bc++;
    res+=(fib(bc+2)-1);
    res%=mod;
  }
  cout << res << '\n';
  return 0;
}
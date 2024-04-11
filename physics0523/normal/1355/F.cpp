#include<bits/stdc++.h>

using namespace std;

bool isprime(long long x){
  if(x<=1){return false;}
  for(long long i=2;i*i<=x;i++){
    if(x%i==0){return false;}
  }
  return true;
}

long long ask(long long x){
  cout << "? " << x << '\n';
  fflush(stdout);
  long long res;
  cin >> res;
  return res;
}

void ans(long long x){
  cout << "! " << x << '\n';
  fflush(stdout);
}

int main(){
  int tc;
  cin >> tc;
  while(tc>0){
    tc--;
    long long ul=2;
    vector<long long> pf;
    for(int i=0;i<17;i++){
      long long av=1;
      vector<long long> cd;
      while(1){
        if(!isprime(ul)){ul++;continue;}
        double dv=av;dv*=ul;
        if(dv>3e18){break;}
        if(av*ul>1000000000000000000){break;}
        cd.push_back(ul);
        av*=ul;
        ul++;
      }
      long long r=ask(av);
      for(auto &nx : cd){
        if(r%nx==0){pf.push_back(nx);}
      }
    }
    while(pf.size()<10){pf.push_back(1);}
    long long res=1;
    for(int i=0;i<5;i++){
      long long av=1;
      if(pf[2*i]>1){
        while(1){
          double dv=av;dv*=pf[2*i];
          if(dv>3e9){break;}
          if(av*pf[2*i]>1000000000){break;}
          av*=pf[2*i];
        }
      }
      if(pf[2*i+1]>1){
        while(1){
          double dv=av;dv*=pf[2*i+1];
          if(dv>3e18){break;}
          if(av*pf[2*i+1]>1000000000000000000){break;}
          av*=pf[2*i+1];
        }
      }
      long long r=ask(av);
      if(pf[2*i]>1){
        long long ce=1;
        while(r%pf[2*i]==0){
          r/=pf[2*i];ce++;
        }
        res*=ce;
      }
      if(pf[2*i+1]>1){
        long long ce=1;
        while(r%pf[2*i+1]==0){
          r/=pf[2*i+1];ce++;
        }
        res*=ce;
      }
    }
    ans(max(res+7,res*2));
  }
  return 0;
}
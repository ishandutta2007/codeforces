#include<bits/stdc++.h>

using namespace std;

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
  int n;
  cin >> n;
  long long st=1,fi=1e7;
  while(st<=fi){
    long long te=(st+fi)/2;
    if(ask(te)==1){fi=te-1;}
    else{st=te+1;}
  }
  long long res=st;
  for(int i=2;i<=n;i++){
    long long av=max(1ll,((res-1)/i));
    long long ef=ask(av);
    if(ef>0){res=min(ef*av,res);}
  }
  ans(res);
  return 0;
}
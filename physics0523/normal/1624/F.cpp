#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int n,rw=0;
int pres=0;

int ask(int x){
  int ap=x-rw;
  int dlt=0;
  if(ap<0){
    dlt=ceil(-ap,n);
    ap+=n*dlt;
  }
  if(ap==0){return pres-dlt;}

  cout << "+ " << ap << '\n';
  fflush(stdout);
  int res;
  cin >> res;
  pres=res;
  rw+=ap;
  return res-dlt;
}

void ans(int x){
  cout << "! " << x << '\n';
  fflush(stdout);
  return;
}

int main(){
  cin >> n;
  int st=1,fi=n-2;
  while(st<=fi){
    int te=(st+fi)/2;
    if(ask(te)==0){st=te+1;}
    else{fi=te-1;}
  }
  ans(n-st+rw);
  return 0;
}
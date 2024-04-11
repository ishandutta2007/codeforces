#include<bits/stdc++.h>

using namespace std;

long long f(long long l,long long r,long long sig){
  if(l>r){return -1;}
  long long st=l,fi=r;
  while(fi-st>=5){
    long long t1=(2*st+fi)/3;
    long long t2=(st+2*fi)/3;
    long long v1=t1*(sig-t1);
    long long v2=t2*(sig-t2);
    if(v1<v2){st=t1+1;}
    else{fi=t2-1;}
  }
  long long res=0;
  for(int i=st;i<=fi;i++){res=max(i*(sig-i),res);}
  return res;
}

int main(){
  long long l,r;
  cin >> l >> r;
  long long res=0;
  long long sig=10;
  for(int i=1;i<=10;i++){
    res=max(f(max(l,(sig/10)),min(r,sig-1),sig-1),res);
    sig*=10;
  }
  cout << res << '\n';
  return 0;
}
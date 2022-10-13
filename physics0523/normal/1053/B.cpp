#include<bits/stdc++.h>

using namespace std;

long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){
    cin >> nx;
    nx=lldsumb(nx,2);
  }
  long long rw=0,k=0,g=0;
  g++;
  for(int i=0;i<n;i++){
    rw+=a[i];
    if(rw%2){k++;}
    else{g++;}
  }
  long long res=0;
  if(k>=2){res+=llnCr(k,2);}
  if(g>=2){res+=llnCr(g,2);}
  for(int i=0;i<n;i++){
    long long sig=0,mxm=0;
    for(int j=i;j<min(n,i+100);j++){
      sig+=a[j];
      mxm=max(a[j],mxm);
      if(sig%2==0 && mxm>(sig/2)){res--;}
    }
  }
  cout << res << '\n';
  return 0;
}
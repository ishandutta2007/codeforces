#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,y;
  cin >> x >> y;
  if(y%x!=0){cout << "0\n";return 0;}
  y/=x;
  vector<long long> st;
  x=y;
  for(long long i=2;i*i<=x;i++){
    if(x%i){continue;}
    st.push_back(i);
    while(x%i==0){x/=i;}
  }
  if(x>1){st.push_back(x);}
  int ss=st.size();
  long long res=0;
  for(int i=0;i<(1<<ss);i++){
    long long pd=1;
    int cnt=0;
    for(int j=0;j<ss;j++){
      if(i&(1<<j)){
        pd*=st[j];
        cnt++;
      }
    }
    res+=mod;
    if(cnt%2){res-=power(2,(y/pd)-1);}
    else{res+=power(2,(y/pd)-1);}
    res%=mod;
  }
  cout << res << '\n';
  return 0;
}
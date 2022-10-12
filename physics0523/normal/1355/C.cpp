#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a,b,c,d;
  cin >> a >> b >> c >> d;
  long long lm=a+b,rm=b+c;
  vector<long long> rw(1048576,0);
  for(long long i=1048574;i>=0;i--){
    long long cur=min(min(b-a+1,c-b+1),max(0ll,min(i-lm,rm-i)+1));
    rw[i]=rw[i+1]+cur;
  }
  long long res=0;
  for(long long i=c;i<=d;i++){
    //cout << i << ' ' << rw[i] << '\n';
    res+=rw[i+1];
  }
  cout << res << '\n';
  return 0;
}
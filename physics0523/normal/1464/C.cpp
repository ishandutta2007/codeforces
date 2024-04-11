#include<bits/stdc++.h>

using namespace std;

long long ctn(char c){
  return (1ll<<(c-'a'));
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n;
  long long t;
  string s;
  cin >> n >> t >> s;
  t+=ctn(s[n-2]);
  t-=ctn(s[n-1]);
  n-=2;
  long long bkt[1024]={0};
  for(long long i=0;i<n;i++){
    t+=ctn(s[i]);
    bkt[(s[i]-'a'+1)]++;
  }
  if(t<0){cout << "No\n";return 0;}
  if(t%2==1){cout << "No\n";return 0;}
  //cout << t << '\n';

  for(long long i=1;i<=26;i++){
    if(t%(1ll<<(i+1))){
      if(bkt[i]==0){cout << "No\n";return 0;}
      bkt[i]--;
      t-=(1ll<<i);
    }
    bkt[i+1]+=(bkt[i]/2);
  }
  if(t>bkt[27]*(1ll<<27)){cout << "No\n";return 0;}

  cout << "Yes\n";
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long get_rand(long long lim,mt19937_64 &eg){
  return (long long)(eg()%lim);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  uint_fast64_t seed=123456789012345678;
  mt19937_64 engine(seed);
  int n;
  cin >> n;
  vector<int> a(n);
  int sig=0;
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
  }
  int mode;
  if(2*sig <= n*n){mode=1;}
  else{mode=0;}
  while(1){
    vector<string> s(n+1);
    for(int i=0;i<=n;i++){
      for(int j=0;j<n;j++){s[i].push_back('0');}
    }
    vector<int> p;
    for(int i=0;i<=n;i++){p.push_back(i);}
    for(int j=0;j<n;j++){
      shuffle(p.begin(),p.end(),engine);
      int rem=a[j];
      if(mode==1){
        s[j][j]='1';
        rem--;
      }
      for(auto &nx : p){
        if(rem==0){break;}
        if(nx==j){continue;}
        s[nx][j]='1';
        rem--;
      }
    }
    sort(s.begin(),s.end());
    bool isng=false;
    for(int i=1;i<s.size();i++){
      if(s[i-1]==s[i]){isng=true;break;}
    }
    if(isng){continue;}
    cout << n+1 << '\n';
    for(auto &nx : s){cout << nx << '\n';}
    return 0;
  }
  return 0;
}
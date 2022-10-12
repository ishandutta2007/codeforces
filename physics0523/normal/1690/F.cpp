#include<bits/stdc++.h>

using namespace std;

long long f(string s){
  int l=s.size();
  for(long long i=1;;i++){
    if(l%i){continue;}
    bool jud=true;
    for(int j=0;j<l;j++){
      if(s[j]!=s[(j+i)%l]){jud=false;break;}
    }
    if(jud){return i;}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string s;
    cin >>  s;
    vector<int> p(n);
    for(auto &nx : p){
      cin >> nx;
      nx--;
    }
    long long res=1;
    vector<bool> fl(n,true);
    for(int i=0;i<n;i++){
      if(!fl[i]){continue;}
      string cs;
      int tg=i;
      while(fl[tg]){
        fl[tg]=false;
        cs.push_back(s[tg]);
        tg=p[tg];
      }
      res=lcm(res,f(cs));
    }
    cout << res << '\n';
  }
  return 0;
}
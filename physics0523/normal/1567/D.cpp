#include<bits/stdc++.h>

using namespace std;

int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int intpow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int s,n;
    cin >> s >> n;
    vector<int> res;
    string ts=to_string(s);
    vector<int> vs;
    int ds=0;
    for(auto &nx : ts){
      vs.push_back(nx-'0');
      ds+=(nx-'0');
    }
    //cout << ds << ':';
    while(ds<n){
      for(int i=vs.size()-2;i>=0;i--){
        if(vs[i]!=0){vs[i]--;vs[i+1]+=10;break;}
      }
      ds+=9;
    }
    // for(auto &nx : vs){cerr << nx << ',';}cerr << ".\n";
    while(n>1){
      int tg=0;
      for(int i=1;i<vs.size();i++){
        if(vs[tg]<vs[i]){tg=i;}
      }
      res.push_back(intpow(10,vs.size()-1-tg));
      vs[tg]--;
      n--;
    }
    int last=0;
    for(auto &nx : vs){
      last*=10;
      last+=nx;
    }
    res.push_back(last);
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}
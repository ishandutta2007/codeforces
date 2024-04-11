#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k,x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    long long ac=0;
    vector<long long> av;
    for(auto &nx : s){
      if(nx=='*'){
        ac++;
      }
      else{
        av.push_back(ac);
        ac=0;
      }
    }
    av.push_back(ac);
    vector<long long> bv(av.size(),0);
    for(int i=av.size()-1;i>=0;i--){
      //cerr << av[i] << ' ' << x << '\n';
      bv[i]=x%(1+k*av[i]);
      x/=(1+k*av[i]);
    }
    for(int i=0;i<av.size();i++){
      for(int j=0;j<bv[i];j++){cout << 'b';}
      if(i!=av.size()-1){cout << 'a';}
    }
    cout << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long res=llnCr(n,3);
    Graph top(n+5),dif(n+5);
    for(int i=0;i<n;i++){
      long long p,q;
      cin >> p >> q;
      top[p].push_back(q);
      dif[q].push_back(p);
    }
    long long sub=0;
    for(auto &nx : top){
      //if(nx.size()>=3){res-=llnCr(nx.size(),3);}
      for(auto &ny : nx){
        sub+=((long long)dif[ny].size()-1)*((long long)nx.size()-1);
      }
    }
    for(auto &nx : dif){
      //if(nx.size()>=3){res-=llnCr(nx.size(),3);}
      for(auto &ny : nx){
        sub+=((long long)top[ny].size()-1)*((long long)nx.size()-1);
      }
    }
    sub/=2;
    cout << res-sub << '\n';
  }
  return 0;
}
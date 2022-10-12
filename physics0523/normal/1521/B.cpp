#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using pipi=pair<pi,pi>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    int tg=0;
    for(int i=0;i<n;i++){
      if(a[tg]>a[i]){tg=i;}
    }
    vector<pipi> res;
    for(int i=0;i<n;i++){
      if(i%2!=tg%2){
        res.push_back({{i+1,tg+1},{1000000007,a[tg]}});
      }
    }
    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.first.first << ' ';
      cout << nx.first.second << ' ';
      cout << nx.second.first << ' ';
      cout << nx.second.second << '\n';
    }
  }
  return 0;
}